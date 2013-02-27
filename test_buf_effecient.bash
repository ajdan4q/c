#!/bin/bash

. /root/bash/debug.sh
test_file=test_file

# create test file
if [[ ! -f $test_file ]]; then
	dd if=/dev/zero of=$test_file bs=1M count=700
fi

# generate test bufsize
a=1024
for ((i=0; i<14; i++)); do
	debug echo $a
	time ./cp_stdin_to_stdout $a <$test_file  > /dev/null
	(( a<<=1 ))
	mv $test_file test_file$i
	test_file=test_file$i
	debug echo $test_file
done

mv $test_file test_file
