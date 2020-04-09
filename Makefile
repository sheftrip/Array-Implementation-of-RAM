

menu: freeListFunctions.o main.o menuOptions.o
	gcc freeListFunctions.o main.o menuOptions.o -o menu

freeListFunctions.o:freeListFunctions.c freeListFunctions.h
	gcc -c freeListFunctions.c

main.o: main.c menuOptions.c menuOptions.h
	gcc -c main.c

menuOptions.o: menuOptions.c menuOptions.h #freeListFunctions.c freeListFunctions.h
	gcc -c menuOptions.c

clean:
	rm *.o menu