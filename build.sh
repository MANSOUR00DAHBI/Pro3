#!/bin/sh 
echo "Started Compler "
set -xe 

gcc -o build/Setup source.c -Wall -Wextra -lm 
#gcc -o build/detab detab.c  -Wall -Wextra -lm 
#gcc -o build/tab3 det3.c  -Wall -Wextra -lm
#gcc -o build/CM Circl_Key_move.c  -Wall -Wextra -lm
#gcc -o build/C_W Circl_win.c  -Wall -Wextra -lm
#gcc -o build/C_M1 Circl1_move.c  -Wall -Wextra -lm
#gcc -o build/C_W1 Circl1_win.c  -Wall -Wextra -lm
#gcc -o build/Wind win.c  -Wall -Wextra -lm
#gcc -o build/W2 win2.c  -Wall -Wextra -lm






 echo "End Compiler"
