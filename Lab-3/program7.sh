#!/bin/sh

echo "Enter three numbers: "
read n1 n2 n3

if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
    max=$n1
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then
    max=$n2
else
    max=$n2
fi

echo "Largest number: $max"
