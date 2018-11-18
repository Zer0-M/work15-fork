all : fork.o
	gcc -o forks fork.c
fork.o: fork.c
	gcc -c fork.c
run:
	./forks
clear:
	rm forks *.o 