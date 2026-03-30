CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/todo.c test/test.c
OBJ = todo.o main.o test.o
all: todo run_test

todo:$(OBJ)
	$(CC) $(OBJ) -o _todo

run_test:$(OBJ)	
	$(CC) $(OBJ) -o run_test
	
main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

todo.o: src/todo.c
	$(CC) $(CFLAGS) -c src/todo.c

test.o: test/test.c
	$(CC) $(CFLAGS) -c test/test.c -o test.o
clean:
	rm -f *.o todo run_test
