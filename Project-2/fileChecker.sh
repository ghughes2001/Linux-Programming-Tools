#!/bin/bash

#Author: Grant Hughes
#Take the name of a directory as a parameter and a string. Verify that the first parameter is a directory, output an error message, and
#terminate, same if more than two parameters are given. The second parameter can be anything. Loop through all files in this directory
#and display their names. However, if one of the names exactly matches the second parameter, output INVALID FILE EXISTS and terminate
#the script. For all the files in that directory, display only those that contain (but do not exactly match) the second input string.
#Do so with the following message: WARNING: Danger detected in name X, where X is replaced with the
#fle's actual name that contained our second argument. Display the number of files and directories pre#sent inside the given directory.


dirName="$1"

if [[ -d $dirName ]] ; then
        echo "$dirName is a directory."
else
        echo "Not a directory"
        exit 1
fi

if [[ $# -gt 2 ]] ; then
        echo "Too many arguments"
        exit 1
fi

arg2="${dirName}/$2"

for file in "${dirName}/"*
do
        echo $file
        if [ "${arg2}" == $file ] ; then
                echo "INVALID FILE EXISTS"
                exit 1
        fi
done

argument2="$2"

for i in "${dirName}/"*
do
        if grep -q -i "$argument2" $i ; then
                echo "WARNING: Danger detected in name "$i""
        fi
done


dirCount=$(ls -l $dirName | grep ^[d] | wc -l)
fileCount=$(ls -l $dirName | grep ^[-] | wc -l)

echo "Directory count is: $dirCount"
echo "File count is: $fileCount"
