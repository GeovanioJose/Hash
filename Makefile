all:Hash

Hash:main.o Hash.o
	gcc Hash.o main.o -o Hash

Hash.o:Hash.c
	gcc -c Hash.c -o Hash.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f Hash *.o
