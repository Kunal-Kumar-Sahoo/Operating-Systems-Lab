#!/bin/sh

echo "Enter a term: "
read n

echo "Fibonacci series: "
a=0
b=1
echo -n "$b "

for ((i=1;i<$n;i++))
do
    c=$(( a+b ))
    a=$b
    b=$c
    echo -n "$c "
done
echo
