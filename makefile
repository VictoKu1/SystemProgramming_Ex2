CC=gcc
AR=ar
FLAGS= -Wall -g

all: libmyBank.a main
main: main.o libmyBank.a
	$(CC) $(FLAGS) -o main main.o libmyBank.a 
libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c myBank.h
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c myBank.h	

.PHONY: clean all 

clean:
	rm -f *.o *.a *.so *.gch main