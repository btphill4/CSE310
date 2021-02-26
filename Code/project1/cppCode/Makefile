EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of the shell variable EXEC which is run.
# run depends on the files main.o util.o heap.o
$(EXEC): Heap.o
# run is created by the command g++ -o run main.o util.o
#note that the tab before $(CC) is REQUIRED
	$(CC) -o $(EXEC) Heap.o

Heap.o: Heap.hpp Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp

clean	:
		rm *.o 
