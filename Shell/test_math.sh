#!/bin/sh

a=90

if [ $a -gt 89 ]; then
    echo "a > 90"
elif [ $a -gt 69 ]; then
    echo "a > 70"
elif [ $a -gt 44 ]; then
    echo "a > 45"
elif [ $a -gt 19 ]; then
    echo "a > 20"
else
    echo "a >= 0"
fi
