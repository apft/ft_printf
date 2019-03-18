#!/bin/sh

ALLOWED_TYPES="float float_hexa float_limits float_subnormal float_long_dbl"

usage()
{
	echo "usage: $0 test_type [new] [debug]"
	echo ""
	echo "where 'test_type' in {${ALLOWED_TYPES}}"
	exit 1
}

if [ $# -lt 1 ]; then
	usage
fi

for type in ${ALLOWED_TYPES}
do
	if [ "$1" = "$type" ]; then
		TEST_TYPE="$1"
		break
	fi
done

if [ ! "${TEST_TYPE}" ]; then
	echo "unknown type"
	usage
fi

debug=0
if [ "$2" = "debug" -o "$3" = "debug" ]; then
	echo "debug"
	debug=1
fi

FOLDER="test_float"
delim="\x5c"
data="format_${TEST_TYPE}.txt"
if [ ! -f ${data} ]; then
	echo "no data file"
	exit 1
fi

template_folder="template"
if [ ! -d ${template_folder} ]; then
	echo "template directory does not exist"
	exit 1
fi

template_launcher=${template_folder}/${TEST_TYPE}/00_launcher_${TEST_TYPE}.c
template_header=${template_folder}/${TEST_TYPE}/test_${TEST_TYPE}.h
if [ ! \( -f ${template_launcher} \) -o ! \( -f ${template_header} \) ]; then
	echo "one or more template files are missing"
	exit 2
fi

folder_name="${FOLDER}/test_${TEST_TYPE}"
folder="../${folder_name}"
launcher="$folder/00_launcher.c"
header="$folder/test_${TEST_TYPE}.h"

makefile_folder="../makefiles"
makefile="${makefile_folder}/makefile_${TEST_TYPE}.mk"

if [ "$2" == "new" ]; then
	[ "$debug" -eq 1 ] && echo "Redo all files" && echo "clear all old files"
	[ -f $makefile ] && rm $makefile
	[ -d $folder ] && rm -rf $folder
fi

[ ! -d "$folder" ] && mkdir -p $folder
if [ ! -f $launcher ]
then
	[ "$debug" -eq 1 ] && echo "get template file: ${template_launcher}"
	cp ${template_launcher} $launcher
fi
if [ ! -f "$header" ]
then
	[ "$debug" -eq 1 ] && echo "get template file: ${template_header}"
	cp ${template_header} $header
fi

includes="<stdio.h> <string.h> <stdlib.h> <math.h> <float.h> \"ft_printf.h\" \"utils.h\""
variables="\tint\t\terror;\n\tchar\t*format;\n\tchar\tstr_printf[BUFF_SIZE];\n\tchar\t*out;\n\tint\t\tret;\n\tint\t\tret_exp;\n\tint\t\tdiff;\n"

read_block()
{
	in_block=-1;
	while read data_line
	do
		[ "${data_line}" = "end_block" ] && in_block=0;
		if [ ${in_block} -eq 1 ]
		then
			loop=$((loop + 1))
			[ "$loop" -le 9 ] && prefix="00$loop"
			[ "$loop" -ge 10 -a $loop -le 99 ] && prefix="0$loop"
			[ "$loop" -ge 100 ] && prefix="$loop"
			title=`echo ${data_line} | cut -d ',' -f 1 | cut -d \" -f 2 | sed "s/#/$1 ${count[$(get_index_count $type)]}/"`
			title=`echo \"$prefix $title\"`
			proto=`echo ${data_line} | cut -d ',' -f 2`
			proto="${proto}_${type}_${count[$(get_index_count $type)]}"
			type_var=`echo ${data_line} | cut -d ',' -f 3`
			value=`echo ${data_line} | cut -d ',' -f 4`
			file="${prefix}_${proto}_${count[$(get_index_count $type)]}.c"
			nbr_arg=$(( `echo $format | tr -dc '|' | wc -c` - 1))
			#[ "$debug" -eq 1 ] && echo $type   ${count[$(get_index_count $type)]}   $title   $proto   $value   $file   $nbr_arg
			if [ ! -f "$folder/$file" ]
			then
				[ "$debug" -eq 1 ] && echo "generating file: $file"
				{
					for inc in $includes
					do
						echo "#include $inc"
					done
					echo
					echo "int\t\t$proto(void)"
					echo "{\n$variables\t${type_var}\t\tn;\n"
					echo "\tbzero(str_printf, BUFF_SIZE);"
					echo "\tformat = $format;"
					echo "\tn = $value;"
					printf "\tret_exp = sprintf(str_printf, format"
					for i in `seq ${nbr_arg}`
					do
						printf ", n"
					done
					echo ");"
					printf "\tret = ft_asprintf(&out, format"
					for i in `seq ${nbr_arg}`
					do
						printf ", n"
					done
					echo ");\n"
					echo "\tdiff = strcmp(out, str_printf);"
					echo "\terror = ret != ret_exp || diff;"
					echo "\tif (error)"
					echo "\t{"
					if [ "${TEST_TYPE}" != "float_long_dbl" ]; then
						echo "\t\tprintf(\"%.50f\\\n\", n);"
					else
						echo "\t\tprintf(\"%.50Lf\\\n\", n);"
					fi
					echo "\t\tprint_diff(format, ret, ret_exp, str_printf, out, diff);"
					echo "\t}"
					echo "\tfree(out);"
					echo "\treturn (error);"
					echo "}"
				} > $folder/$file
				[ "$debug" -eq 1 ] && echo "add to launcher"
				n_line=`cat $launcher | wc -l | tr -d ' '`
				n=$((n_line - 2))
				{
					head -n $n $launcher
					echo "\tadd_test(&test_list, $title, &$proto);"
					tail -n 2 $launcher
				} > $launcher.tmp
				mv $launcher.tmp $launcher
				[ "$debug" -eq 1 ] && echo "add to header"
				n_line=`cat $header | wc -l | tr -d ' '`
				n=$((n_line - 2))
				{
					head -n $n $header
					echo "int\t\t$proto(void);"
					tail -n 2 $header
				} > $header.tmp
				mv $header.tmp $header
				[ "$debug" -eq 1 ] && echo "add to makefile"
				echo "\t${folder_name}/$file ${delim}" >> $makefile.tmp
			else
				echo "nothing to be done for file: $file"
			fi
		fi
		[ "${data_line}" = "start_block" ] && in_block=1;
	done < ${data_block}
}

get_index_count()
{
	id=0;
	[ $1 = "f" ] && id=0
	[ $1 = "a" ] && id=1
	[ $1 = "A" ] && id=2
	echo $id
}

inc_count()
{
	[ $1 = "f" ] && let count[0]+=1
	[ $1 = "a" ] && let count[1]+=1
	[ $1 = "A" ] && let count[2]+=1
}

data_block="data_block.txt"
end="end_block"
[ "$debug" -eq 1 ] && echo "extract data block"
head -n $(grep -n $end $data | cut -d ':' -f 1 | head -n 1) $data > ${data_block}

loop=0;
block=-1;
# count: f a A
count=(0 0 0)
while read line
do
	[ "$line" = "start_block" ] && block=1;
	if [ "$block" -eq 0 ]
	then
		type=`echo $line | cut -d ',' -f 1`
		format=`echo $line | cut -d ',' -f 2`
		read_block $type
		let count[$(get_index_count $type)]+=1
	fi
	[ "$line" = "end_block" ] && block=0;
done < $data

# MAKEFILE
if [ -f "${makefile}.tmp" ]; then
	[ "$debug" -eq 1 ] && echo "assemble makefile"
	echo "C_FILES_$(echo ${TEST_TYPE} | tr '[:lower:]' '[:upper:]')	:= ${FOLDER}/test_${TEST_TYPE}/00_launcher.c ${delim}" > ${makefile}
	sed '$ s/..$//' ${makefile}.tmp >> ${makefile}
	rm ${makefile}.tmp
fi
rm ${data_block}
