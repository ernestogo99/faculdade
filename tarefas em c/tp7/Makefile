all:	main

main:	listaencad.o  mainl.o
	gcc listaencad.o  mainl.o -o main


listaencad.o:	listaencad.c listaencad.h
	gcc -c listaencad.c

mainl.o:	mainl.c listaencad.h
	gcc -c mainl.c

clean:
	rm -f *.o main

