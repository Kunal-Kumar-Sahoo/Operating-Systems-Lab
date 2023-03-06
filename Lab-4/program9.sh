#!/bin/bash
echo $1 $2 $3 $4 $5
if [ $# -eq 5 ]
then
    echo "Valid arguments"
else
    echo "Invalid arguments"
fi
