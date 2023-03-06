#!/bin/sh

echo "Enter size: "
read N
sum=0

echo "Enter $N numbers:"
for (( i=0;i<N;i++ ))
do
    read n
    sum=$(( sum+n  ))
done
echo "Sum: $sum"
