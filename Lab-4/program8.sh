#!/bin/bash
echo "Enter three numbers: "
read n1 n2 n3
largest=$n1
if [ $n2 -gt $n1 ]
then
    largest=$n2
    if [ $n3 -gt $n2 ]
    then
        largest=$n3
    fi
fi
total=$(( n1 + n2 +n3 ))
avg=$(( total / 3 ))
echo "Largest of three: $largest"
echo "Total of three is: $total"
echo -n "Average of three is: "
echo "scale=2;$total/3" | bc

