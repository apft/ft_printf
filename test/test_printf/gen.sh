#!/bin/sh

debug=1;

template_folder="template"
template_launcher=${template_folder}/00_launcher.c
template_header=${template_folder}/test_int.h

folder="test_int"
[ ! -d $folder ] && mkdir $folder
launcher="$folder/00_launcher.c"
header="$folder/test_int.h"
if [ ! -f $launcher ]
then
	[ $debug -eq 1 ] && echo "get template file: ${template_launcher}"
	cp ${template_launcher} $launcher
fi
if [ ! -f $header ]
then
	[ $debug -eq 1 ] && echo "get template file: ${template_header}"
	cp ${template_header} $header
fi

includes="<stdio.h> <string.h> <stdlib.h> \"ft_printf.h\" \"utils.h\""

variables="\tint\t\terror;\n\tchar\t*format;\n\tchar\tstr_printf[BUFF_SIZE];\n\tchar\t*out;\n"

loop=0;
while read line
do
	loop=$((loop + 1))
	[ $loop -le 9 ] && prefix="0$loop" || prefix=$loop
	title=`echo $line | cut -d ',' -f 1`
	name=`echo $line | cut -d ',' -f 2`
	file="${prefix}_${name}.c"
	type=`echo $line | cut -d ',' -f 3`
	nbr_arg=`echo $line | cut -d ',' -f 4`
	format=`echo $line | cut -d ',' -f 5`
	value=`echo $line | cut -d ',' -f 6`
	if [ ! -f "$folder/$file" ]
	then
		[ $debug -eq 1 ] && echo "generating file: $file"
		{
			for inc in $includes
			do
				echo "#include $inc"
			done
			echo
			echo "int\t\t$name(void)"
			echo "{\n$variables\t$type\t\tn;\n"
			echo "\tbzero(str_printf, BUFF_SIZE);"
			echo "\tformat = $format;"
			echo "\tn = $value;"
			printf "\tsprintf(str_printf, format"
			for i in `seq ${nbr_arg}`
			do
				printf ", n"
			done
			echo ");"
			printf "\tft_printf_str(&out, format"
			for i in `seq ${nbr_arg}`
			do
				printf ", n"
			done
			echo ");\n"
			echo "\terror = strcmp(str_printf, out);"
			echo "\tif (error)"
			echo "\t\tprint_diff(format, str_printf, out);"
			echo "\tfree(out);"
			echo "\treturn (error);"
			echo "}"
		} > $folder/$file
		[ $debug -eq 1 ] && echo "add to launcher"
		n_line=`wc -l $launcher | cut -d ' ' -f 7`
		n=$((n_line - 2))
		{
			head -n $n $launcher
			echo "\tadd_test(&test_list, $title, &$name);"
			tail -n 2 $launcher
		} > $launcher.tmp
		mv $launcher.tmp $launcher
		[ $debug -eq 1 ] && echo "add to header"
		n_line=`wc -l $header | cut -d ' ' -f 7`
		n=$((n_line - 2))
		{
			head -n $n $header
			echo "int\t\t$name(void);"
			tail -n 2 $header
		} > $header.tmp
		mv $header.tmp $header
	else
		echo "nothing to be done for file: $file"
	fi
done < int_format.txt
