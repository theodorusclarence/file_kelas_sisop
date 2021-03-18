#!/bin/bash

echo "Nama script : $0"
echo "Argumen ke-1 : $1"
echo "Argumen ke-2 : $2"
echo "Hai $1, selamat datang di kelas $2!"
echo "Total argumen : $#"
echo "Semua argumen : $*"
echo "PID : $$" 

# $0 	Berisi nama file script yang sedang dijalankan
# $n 	n disini adalah angka desimal positif yang sesuai dengan posisi argumen (argumen pertama adalah $1, argumen kedua adalah $2, dst)
# $# 	Jumlah argumen yang diinput pada script
# $* 	Semua argumen $n
# $? 	Status exit dari perintah terakhir yang dijalankan
# $$ 	Proses ID (PID) shell saat ini