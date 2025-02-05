#!/bin/sh 
echo "Started Compler "
set -xe 

gcc -o build/Setup source.c -Wall -Wextra -lm 
gcc -o build/detab detab.c  -Wall -Wextra -lm 
gcc -o build/tab tab2.c  -Wall -Wextra -lm 
gcc -o build/tab3 det3.c  -Wall -Wextra -lm 
echo "End Compiler"
