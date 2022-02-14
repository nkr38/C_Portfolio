#!/bin/bash
# prod_list - a database script that saves to a text file.
#
# Commands:
# quit
#   Break out of your input loop, quit the program
# setdb
#   Set the filename for the databse file
# add
#   Add or update an item to (int) the database
# delete
#   Remove an item from the database
# printdb
#   Print all the lines from the database
#
# Noah Robinson
# 2/2022
#

isSet=0

while [[ $input != "quit" ]]
do
    echo -n "% "
    read -r input arg1 arg2

    case $input in
        setdb)
            if [[ -z "$arg1" ]] ; then
                echo "Missing Argument"
            else
                if [[ ! -z "$arg2" ]] ; then
                    echo "Extra arguments ignored"
                fi
                if [[ -f "$arg1" && -r "$arg1" ]] ; then
                    db=$arg1
                    echo "Database set to $arg1"
                    isSet=1
                elif [[ -f "$arg1" && ! -r "$arg1" ]] ; then
                    echo "File $arg1 not readable"
                elif [[ ! -f "$arg1" ]] ; then
                    touch "$arg1"
                    db=$arg1
                    echo "File $arg1 created. Database set to $arg1"
                    isSet=1
                fi
            fi
            ;;
        add)
            if [[ $isSet != 1 ]] ; then
                echo "Database has not been set."
            else
                if [[ -z "$arg1" || -z "$arg2" ]] ; then
                    echo "Incorrect syntax."
                else
                    if grep -q "$arg1" "$db" ; then
                        sed -ir "s/$arg1.*/$arg1:$arg2/g" $db
                        printf "%s has been updated to %.2f\n" "$arg1" "$arg2"
                    else
                        echo "$arg1:$arg2" >> "$db"
                        echo "$arg1:$arg2 has been added to the database"
                    fi
                fi
            fi
            ;;
        delete)
            if [[ $isSet != 1 ]] ; then
                echo "Database has not been set."
            else
                if [[ -z "$arg1" || ! -z "$arg2" ]] ; then
                    echo "Incorrect syntax."
                else
                    if grep -q "$arg1" "$db" ; then
                        sed -ri "/^"$arg1"/d" "$db"
                        echo "$arg1 has been deleted from \`$db\`."
                    else
                        echo "$arg1 does not exist in \`$db\`."
                    fi
                fi
            fi
            ;;
        printdb)
            if [[ $isSet != 1 ]] ; then
                echo "Database has not been set."
            else
                echo "  Product      Price"
                echo "------------  -------"
                awk -F: '{printf"%-12.12s  $%6.2f\n", $1,$2}' $db
            fi
            ;;
        *)
            if [[ "$input" != "quit" ]] ; then
                echo "Unrecognised command"
            fi
            ;;
    esac
done
