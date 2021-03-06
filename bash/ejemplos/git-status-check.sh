#!/bin/bash

#declare -a OLD_ARR=("quick-refs" "tef" "elisp-functions" "r-functions")
declare -a ARR=($(find -maxdepth 2 -name ".git"))
declare MAX=0
declare MAXSTR=""

for ((n=0; n < ${#ARR[@]} ; n++))
do
    ARR[$n]=${ARR[$n]//\/.git/}
done



for i in "${ARR[@]}"
do
    if [[ "${#i}" -gt "$MAX" ]]
    then
	MAX=${#i}
	MAXSTR=$i
    fi
    
done

printf "\n"

for DIR in "${ARR[@]}"
do
    SPACE=""    
    for ((n=0 ; n < 4 + $MAX - ${#DIR} ; n++))
    do
	SPACE="${SPACE} "
    done
    
    printf "In %s:%s" ${DIR//.\//} "${SPACE}"
    
    STATUS_OUT=$(git -C "$DIR" status --porcelain)
    LOG_OUT=$(git -C "$DIR" log origin/master..HEAD)

    (([[ -z $STATUS_OUT ]] && printf "Nothing to commit.\t") \
	 || printf "Uncommited changes.\t" ) \
	&& (([[ -z $LOG_OUT ]] && printf "Nothing to push.\n") \
		|| printf "Unpushed changes.\n") ; continue;

done
