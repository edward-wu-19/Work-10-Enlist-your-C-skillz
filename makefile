all: main.o
	gcc -o work10 main.o main.h

main.o: main.c main.h
	gcc -c main.c main.h

clean:
	rm -rf work10 main.o

run:
	./work10