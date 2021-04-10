#!/bin/bash

single=3

#Single quote
echo '$single'

#Double quote
echo "$single"

#Backslash
echo \<-\$1500.\*\*\>\; \(update\?\) \[y\|n\]

#Backquote
dmn=`pwd`
echo "Dimana kita? " $dmn

# Single Quote (') 	Semua metakarakter di antara single quote akan
#                   kehilangan makna khusus
# Double Quote (") 	Sebagian besar metakarakter di antara double quote
#                   akan kehilangan makna khusus, kecuali $, backquote, \$, \', \", \\
# Backslash (\) 	Karakter apa pun setelah backslash akan kehilangan makna
#                   khusus
# Backquote (`) 	Apa pun di antara back quote akan diperlakukan
#                   sebagai perintah dan akan dieksekusi