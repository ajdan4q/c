#!/bin/sh

[ -z "$1" ] && echo "$0 source.c" && exit

#echo "compile c source file [$1] ..."
#IFS="."
read -d"." name <<< "$1"
outfile=$name.out

#outfile=`echo $1|sed 's/\.c$//'`'.out'
gcc -o $outfile $1

#echo "run [$outfile] ..."
./$outfile
#echo "run done! ..."

#echo "clean [$outfile] ..."
rm $outfile -f
