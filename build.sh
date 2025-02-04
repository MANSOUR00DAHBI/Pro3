#!/bin/sh 
echo "Started Compler "
set -xe 

gcc -o build/Setup source.c -Wall -Wextra -lm 

echo "End Compiler"
