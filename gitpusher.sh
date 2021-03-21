#!/bin/bash
msg=$1

git add .
git status

read -r -p "Continue to push? [Y/n] " response

# if not continue
if [[ "$response" =~ ^([nN][oO]|[nN])$ ]]
then
    echo "Canceled commit & push"  
else
    git commit -m "$msg"
    git push
fi