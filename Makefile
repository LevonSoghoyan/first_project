CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/todo.c 
OBJ = todo.o main.o 
TEST_OBJ = test.o src/todo.o
TEST_SRC = test/test.c src/todo.c
all: todo run_test

todo:$(OBJ)
	$(CC) $(OBJ) -o todo

run_test:$(TEST_OBJ)	
	$(CC) $(TEST_OBJ) -o run_test
	
main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

todo.o: src/todo.c
	$(CC) $(CFLAGS) -c src/todo.c

test.o: test/test.c
	$(CC) $(CFLAGS) -c test/test.c -o test.o
clean:
	rm -f *.o todo run_test
