#!/usr/bin/env bash

for ((i=0; i <= 20; i++))
do
    let "value=1<<$i"
    echo "start $i"
    echo "BUFFSIZE: $value" >> result.txt
    /usr/bin/time -a -p -o result.txt ../a.out $value < 1-2.mp4
    echo "" >> result.txt
    echo "end $i"
done
