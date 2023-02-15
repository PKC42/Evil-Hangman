CC = gcc
CFLAGS = -g -Wall --std=c99
OBJ1 = main.o my_string.o generic_vector.o my_tree.o
OBJ2 = unit_test.o test_def.o my_string.o 


all: Evil_Hangman unit_test

Evil_Hangman:$(OBJ1)
	$(CC) $(CFLAGS) -o Evil_Hangman $(OBJ1)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o:my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

generic_vector.o:generic_vector.c generic_vector.h generic.h
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

my_tree.o:my_tree.c my_tree.h generic_vector.h generic.h my_string.h status_and_bool.h
	$(CC) $(CFLAGS) -c my_tree.c -o my_tree.o



unit_test:$(OBJ2)
	$(CC) $(CFLAGS) -o unit_test $(OBJ2)

unit_test.o:unit_test.c unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o

test_def.o:test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o



clean:
	-rm Evil_Hangman unit_test
	-rm *.o
	