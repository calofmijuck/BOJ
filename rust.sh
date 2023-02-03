#!/bin/bash

get_dirname () {
    number=$(($1 / 100 * 100))
    printf $number
}

if [ $# -ne 0 ];
then
    dirname=$(get_dirname $1)
    rustc --edition 2021 -O -o submit Codes/$dirname/$1.rs && ./submit
else
    clippy-driver -D clippy::all submit.rs \
        && rustc --edition 2021 -O -o submit submit.rs \
        && ./submit
fi
