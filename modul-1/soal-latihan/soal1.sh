#!/bin/bash

sum=0


# kalo genap
if [ $(($# % 2)) -eq 0  ]
then 
    echo "Anda belum beruntung, coba lagi."
else
    for n in $@
    do
    sum=$(($sum+$n))
    done
    echo $sum
fi