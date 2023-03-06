#!/bin/sh
echo "Enter a number: "
read n
echo "Entered number is: $n"
reverse=0
while [ $n -gt 0 ]
do
    r=$(( n%10 ))
    reverse=$(( reverse*10+$r ))
    n=$(( n/10 ))
done
echo "Reversed number: $reverse"
