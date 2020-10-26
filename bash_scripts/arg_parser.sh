#!/bin/bash

#Colors
GREEN='\e[1;32m'
BLUE='\e[1;36m'
WITHE='\e[0;37m'
YELLOW='\e[1;33m'
NC='\e[0m'

BOLD=$(tput bold)
NORMAL=$(tput sgr0)

function help () {
echo -e "${YELLOW}Insert menu description here${NC}

Usage: ./$0 [OPTION1] [OPTION2] ... [OPTIONN]

\t${BOLD}-h, --help${NORMAL}
\t\tShow this help menu
\t${BOLD}-a, --opt1${NORMAL}
\t\tNo additional parameter
\t${BOLD}-b, --opt2 <value>${NORMAL}
\t\tWith additional parameter
\t${BOLD}-c, --opt3${NORMAL}
\t\tNo additional parameter
"
}

POSITIONAL=()
while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    -h|--help)
        help
        break
    ;;
    -a|--opt1)
        echo -e "${GREEN}$1${NC} passed, you can add a function call here"
        shift # past argument
    ;;
    -b|--opt2)
        VALUE=$2
        echo -e "${GREEN}$1${NC} passed with value ${GREEN}$VALUE${NC}, you can add a function call here"
        shift # past argument
        shift # past value
    ;;
    -c|--opt3)
        echo -e "${GREEN}$1${NC} passed, you can add a function call here"
        shift # past argument
    ;;
    *)    # unknown options passed
        POSITIONAL+=("$1") # save it in an array for later
        shift # past argument
    ;;
esac
done
