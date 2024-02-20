all: main

main: vetdim.o vetmain.o
	gcc vetdim.o vetmain.o -o main

vetmain.o: vetmain.c vetdim.h
	gcc -c vetmain.c -o vetmain.o

vetdim.o: vetdim.c vetdim.h
	gcc -c vetdim.c -o vetdim.o

clean:
	rm -f main *.o


