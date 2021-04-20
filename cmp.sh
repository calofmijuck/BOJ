#!/bin/bash

get_dirname () {
    number=$(($1 / 100 * 100))
    printf $number
}

if [ $# -ne 0 ];
then
    dirname=$(get_dirname $1)
    g++ Codes/$dirname/$1.cpp -Wall -std=c++17 -o submit -I . ${@:2} && ./submit
else
    g++ submit.cpp -Wall -std=c++17 -o submit && ./submit
fi
