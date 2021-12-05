#!/bin/bash

get_dirname () {
    number=$(($1 / 100 * 100))
    printf $number
}

if [ $# -eq 0 ];
then
    echo "Usage: ./make.sh [problem_number] [file_extension]"
    exit
fi

if [ $# -eq 1 ];
then
    extension="cpp"
else
    extension=$2
fi

dirname=$(get_dirname $1)
mkdir -pv Codes/$dirname

filename=Codes/$dirname/$1.$extension
if [ ! -f $filename ];
then
    touch $filename
    echo "Created $filename."
else
    echo "Error: file already exists."
fi
