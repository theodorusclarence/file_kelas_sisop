#!/bin/bash

# print buat semua
# -F, buat separate (,)
awk -F, '{printf("%.2f\n", $3*$4)}' iris.data > soal3out.txt

# print perkalian, yang ada Iris-setosa nya
awk -F, '/Iris-setosa/ {printf("%.2f\n", $3*$4)}' iris.data > soal3out.txt

# print yang baris 1 (sepal length > 5.4) nya
awk -F, '/Iris-setosa/ {if($1 > 5.4) printf("%.2f\n", $3*$4)}' iris.data > soal3out.txt 

# cara print line number:
# NR

# "Luas petal pada baris %s adalah %.2f\n", NR, $3*$4

#print yang bagus & final
awk -F, '/Iris-setosa/ {if($1 > 5.4) printf("Luas petal pada baris %s adalah %.2f\n", NR, $3*$4)}' iris.data > soal3out.txt 
