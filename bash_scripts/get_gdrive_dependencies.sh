#!/bin/bash

# Definitioins
TRUE=0
FALSE=1

GREEN='\033[1;32m'
NC='\033[0m'

# This list must be in the following format:
#   <google drive file_name>:<google drive file ID>,
# Exemple with two files:
file_list="node_modules_imx.tar.gz:10g10E2e1ONRiD8qDEjoI1Hi1wMbltKB7,mediaserver.tar.gz:1i5i95z8anD648WOLLvOTaYFJycQLvgDn,"

function gdrive_download () {
    arg1=$1 # Google ID of file
    arg2=$2 # File name in google docs

    CONFIRM=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate "https://docs.google.com/uc?export=download&id=$arg1" -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')
    wget -q --load-cookies /tmp/cookies.txt "https://docs.google.com/uc?export=download&confirm=$CONFIRM&id=$arg1" -O $arg2
    rm -rf /tmp/cookies.txt
}

function check_download () {
    arg1=$1 # File name to be checked

	# Getting file absolute path. If statement doesn't accept relative paths
	file_abs_path=$(realpath ~/Downloads/$arg1.part)

    [ -f $file_abs_path ] && return $TRUE || return $FALSE
}

ret=""

echo ""
echo -e "${GREEN}INFO:${NC} In order to download desired google drive files, a firefox tab will open requesting you to put your google account credentials. 
This will be requested for each file to be download by this script. "
echo ""
read -p "Press enter to continue" ret

# Opening file_list as a string in file descriptor 3
exec 3<<<"$file_list"

# Parsing file descriptor 3 content
echo ""
echo "====================================="

while IFS=: read -r -d, i j <&3; do
	rm -f $i

	gdrive_download $j $i.html
	firefox $i.html

	echo "Waiting for user login and download starts"

	check_download $i
	while [ $? -eq $FALSE ]
	do
		sleep 1
		check_download $i
	done

	echo "Downloading $i"

	check_download $i
	while [ $? -eq $TRUE ]
	do
		sleep 1
		ret=$(ls -lha ~/Downloads | grep $i.part)
		echo -n "$ret"
		echo -ne '\r'
		check_download $i
	done
	echo -ne '\n\n'

	mv ~/Downloads/$i .
	rm -rf $i.html
done

echo "====================================="
