#!/bin/sh
# IF Number of args is 2
if [ $# -eq 2 ]; then

	#$1 refers to the first argument
        if [ -d $1 ]; then
                x=$(ls $1 -r | wc -l)
                y=$(grep -r $2 $1 | wc -l)
                echo "The number of files are $x and the number of matching lines are $y"
                exit 0

	else
		echo "The dir does not exists"
	fi
        exit 1

else 

	echo "failed: Pass only 2 arguments!"
        exit 1

fi 
