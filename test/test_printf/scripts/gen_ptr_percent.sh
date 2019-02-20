#!/bin/sh

debug=1;
TEST_TYPE="ptr_percent"

data="${TEST_TYPE}_format.txt"

template_folder="template"
template_launcher=${template_folder}/00_launcher_${TEST_TYPE}.c
template_header=${template_folder}/test_${TEST_TYPE}.h

folder="../test_${TEST_TYPE}"
[ ! -d "$folder" ] && mkdir $folder
launcher="$folder/00_launcher.c"
header="$folder/test_${TEST_TYPE}.h"
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

includes="<stdio.h> <string.h> <stdlib.h> \"ft_printf.h\" \"utils.h\""
variables="\tint\t\terror;\n\tchar\t*format;\n\tchar\tstr_printf[BUFF_SIZE];\n\tchar\t*out;\n\tint\t\tret;\n\tint\t\tret_exp;\n\tint\t\tdiff;\n"

loop=0;
while read line
do
	title=`echo $line | cut -d ',' -f 1 | cut -d \" -f 2`
	proto=`echo $line | cut -d ',' -f 2`
	format=`echo $line | cut -d ',' -f 3`
	args=`echo $line | cut -d ',' -f 4-`
	echo "$title  $proto  $format  $args"
	loop=$((loop + 1))
	[ "$loop" -le 9 ] && prefix="0$loop" || prefix=$loop
	file="${prefix}_${proto}.c"
	title=`echo \"$prefix $title\"`
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
			echo "{\n$variables\n"
			echo "\tbzero(str_printf, BUFF_SIZE);"
			echo "\tformat = $format;"
			echo "\tret_exp = sprintf(str_printf, format, $args);"
			echo "\tret = ft_asprintf(&out, format, $args);"
			echo "\tdiff = strcmp(out, str_printf);"
			echo "\terror = ret != ret_exp || diff;"
			echo "\tif (error)"
			echo "\t\tprint_diff(format, ret, ret_exp, str_printf, out, diff);"
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
	else
		echo "nothing to be done for file: $file"
	fi
done < $data
