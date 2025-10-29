CC=g++ #sets gcc function as a variable for use
TASK1 = Lab10.cpp

task1:  # defines prog as a function and gives it OBJECTS as a param, then function runs $ gcc main.c, isOdd.c isEven.c -o prog | in terminal
	$(CC) $(TASK1) -o task1
run1:
	./task1

clean: # defines a function for cleaning current directory of .o files and prog executable
	rm -rf *.o task1