#!/bin/bash
echo "Enter a number: "
read n
echo "Entered number is $n"
sum=0
while [ $n -gt 0 ]
do
    x=$(( n%10 ))
    sum=$(( sum + $x ))
    n=$(( n/10 ))
done
echo "Sum of digits: $sum"
