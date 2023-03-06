#!/bin/sh

echo "Enter principle amount: "
read p

echo "Enter rate of interest: "
read r

echo "Enter number of years: "
read t

s=$(( p*r*t/100 ))
echo "Simple interest: $s"
