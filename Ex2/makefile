all: main 
main: main.o libmybank.a
	gcc main.o -Wall libmybank.a -o main
main.o: main.c
	gcc -c main.c
libmybank.a: myBank.o
	ar -rcs libmybank.a myBank.o
myBank.o: myBank.c myBank.h
	gcc -c myBank.c
	
clean:
	rm -f *.o *.a
