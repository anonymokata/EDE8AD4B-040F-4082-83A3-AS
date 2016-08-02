CC = gcc
CFLAGS = -I.
DEPS = calculator.h
OBJ = calculator.o calculator_test.o 
LIBS = -lcheck -pthread -lrt -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calculator: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)