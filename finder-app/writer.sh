#!/bin/bash
# Nested if statements
if [ $# -eq 2 ]
    then
    file="$1"
    strcontent="$2"
    if [ -d file ]
        then
        # file does exist, write to it
        echo "$strcontent" > "$file"
    else
        # file does not exit, make new and write to it
        mkdir -p $(dirname $file) && touch $file
        echo "$strcontent" > "$file"
    fi
else
    echo "More or less args are passed"
    exit 1
fi
