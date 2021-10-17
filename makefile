all: main.o
	gcc -o work10 main.o

main.o: main.c
	gcc -c main.c

clean:
	rm -rf work10 main.o

run:
	./work10