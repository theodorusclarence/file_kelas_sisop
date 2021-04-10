#!/bin/bash

# 1 	-eq 	Memeriksa apakah nilai kedua operan sama (==)
# 2 	-ne 	Memeriksa apakah nilai kedua operan tidak sama (!=)
# 3 	-gt 	Memeriksa apakah nilai operan kiri lebih besar daripada operan kanan (>)
# 4 	-lt 	Memeriksa apakah nilai operan kiri lebih kecil daripada operan kanan (<)
# 5 	-ge 	Memeriksa apakah nilai operan kiri lebih besar atau sama dengan operan kanan (>=)
# 6 	-le 	Memeriksa apakah nilai operan kiri lebih kecil atau sama dengan operan kanan (<=)


a=15
b=7

# harus dikasi jarak antar bracket
if [ $a -eq $b ]
then
  echo "$a -eq $b: a sama dengan b"
else
  echo "$a -eq $b: a tidak sama dengan b"
fi