make && make clean

echo "TEST INPUT"

T=1
#1 nada
echo "TEST" $T && T=$((T+1))
./push_swap

echo "===================Error==================="
#2
echo "TEST" $T && T=$((T+1))
./push_swap 1 a 3

#3 error
echo "TEST" $T && T=$((T+1))
./push_swap 1 55975234902485 3

#4 error
echo "TEST" $T && T=$((T+1))
./push_swap 0 2 +2

#5 error
echo "TEST" $T && T=$((T+1))
./push_swap 0 -12 -00012

#6 error
echo "TEST" $T && T=$((T+1))
./push_swap 12a34

#7 error
echo "TEST" $T && T=$((T+1))
./push_swap 12 4 3 5 2 4

#8 error
echo "TEST" $T && T=$((T+1))
./push_swap 0 +0

#9 error
echo "TEST" $T && T=$((T+1))
./push_swap 0 -0

echo "===================OK==================="
#10 ok
echo "TEST" $T && T=$((T+1))
./push_swap 042

#11 ok
echo "TEST" $T && T=$((T+1))
./push_swap 0 0001

#12 ok
echo "TEST" $T && T=$((T+1))
./push_swap 1 +0

#13 ok
echo "TEST" $T && T=$((T+1))
./push_swap 1 -0

#14 ok
echo "TEST" $T && T=$((T+1))
./push_swap -00012

#15 ok
echo "TEST" $T && T=$((T+1))
./push_swap 0 +000013

#16 ok
echo "TEST" $T && T=$((T+1))
./push_swap 0 +1
