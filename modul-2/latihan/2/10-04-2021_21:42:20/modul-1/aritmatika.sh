#!/bin/bash

a=15
b=7

# Menggunakan perintah built-in let
# Menggunakan perintah eksternal expr
# Menggunakan perintah subtitusi $((ekspresi))

#memakai let
let jumlah=$a+$b
let kurang=$a-$b
let kali=$a*$b

let "dafa = 1 + 3" "dafa = 2" "dafa += 3"
echo $dafa

#memakai expr
bagi=`expr $a / $b`

#memakai perintah subtitusi $((ekspresi))
mod=$(($a % $b)) 

echo "a + b = $jumlah"
echo "a - b = $kurang"
echo "a * b = $kali"
echo "a / b = $bagi"
echo "a % b = $mod"

b=$a

echo "a = $a"
echo "b = $b"