#!/bin/bash

make && make clean

T=1
: '
echo "TEST INPUT : Error y nada en el 4"

echo "TEST" $T && T=$((T+1))
./push_swap 1 a 3

echo "TEST" $T && T=$((T+1))
./push_swap 12 4 3 5 2 4

echo "TEST" $T && T=$((T+1))
./push_swap 1 55975234902485 3

echo "TEST" $T && T=$((T+1))
./push_swap

echo "TEST IDENTIDAD: sin output"

echo "TEST" $T && T=$((T+1))
./push_swap 42

echo "TEST" $T && T=$((T+1))
./push_swap 0 1 2 3

echo "TEST" $T && T=$((T+1))
./push_swap 0 1 2 3 4 5 6 7 8 9

echo "SIMPLE VERSION"

echo "TEST" $T && T=$((T+1))
ARG="2 1 0"
echo -n "Instrucciones: " && ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo "Other simple checks"

echo "TEST" $T && T=$((T+1))
ARG="1 5 2 4 3"
echo -n "Instrucciones: " && ./push_swap $ARG | wc -l

#./push_swap $ARG 
./push_swap $ARG | ./checker_linux $ARG
'
: '
echo "Random Tests n=5"

while [ $T -lt 5 ]
do
    echo "TEST" $T && T=$((T+1))
    ARG=$(shuf -i 0-1000 -n 5 | tr "\n" " ")
    #./push_swap $ARG > output$T
    #echo -n "Instrucciones: " && ./push_swap $ARG | wc -l
    ./push_swap $ARG | ./checker_linux $ARG
    #echo $ARG
done
'
: '
ARG="2 6 5 7 10 8 4 3 9 1"
./push_swap $ARG | ./checker_linux $ARG
'

echo "Random Tests n=100"

T=15

while [ $T -lt 18 ]
do
    echo "TEST" $T && T=$((T+1))
    ARG=$(shuf -i 0-1000 -n 100 | tr "\n" " ")
    echo -n "Instrucciones: " && ./push_swap $ARG | wc -l
    ./push_swap $ARG | ./checker_linux $ARG
done

: '
echo "Random Tests n=500"

T=18

while [ $T -lt 21 ]
do
    echo "TEST" $T && T=$((T+1))
    ARG=$(shuf -i 0-1000 -n 500 | tr "\n" " ")
    echo -n "Instrucciones: " && ./push_swap $ARG | wc -l
    ./push_swap $ARG | ./checker_linux $ARG
done
'
: '
ARG=$(shuf -i 0-1000 -n 10 | tr "\n" " ")
./push_swap $ARG
'