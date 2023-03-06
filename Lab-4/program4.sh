#!/bin/sh
echo "Enter two numbers: "
read num1 num2
echo "The sum of these numbers are: "
echo $num1 + $num2 | bc
