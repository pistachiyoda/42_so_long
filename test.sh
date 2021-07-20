for txt in $(ls ./map | grep "err");
do
	echo map/${txt}
	./so_long map/${txt}
	echo $?
	sleep 0.5;
done