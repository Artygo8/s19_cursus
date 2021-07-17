#!/bin/bash

PREFIX=""
FILE="repo_name.txt"
REPO="https://github.com/Artygo8/"


if [[ -e $FILE ]];then
	cat $FILE |while read line; do
		if [[ -n $line ]];then
  			echo $PREFIX$line.git
			git remote add -f $line $REPO$PREFIX$line.git
			git merge -s ours --no-commit --allow-unrelated-histories $line/master || git merge -s ours --no-commit --allow-unrelated-histories $line/main
			git read-tree --prefix=$line/ -u $line/master || git read-tree --prefix=$line/ -u $line/main
			git add --all
			git commit -m "merging $PREFIX$line into subdirectory $line"
		fi
	done
else
	echo "/!\\ Please create a file named $FILE with the names of your repositories. These will be prefixed with \"$PREFIX\"."
fi

