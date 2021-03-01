EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of the shell variable EXEC which is run.
# run depends on the files Main.o Util.o Heap.o
$(EXEC): Main.o Util.o Heap.o
# run is created by the command g++ -o run Main.o Util.o
#note that the tab before $(CC) is REQUIRED
	$(CC) -o $(EXEC) Main.o Util.o Heap.o

# Main .o depends on the files Main.h Main.cpp
Main.o: Main.cpp
# Main.o is created by the g++ -c -Wall Main.cpp
# note that the TAB before $(CC) is REQUIRED...
	$(CC) $(CFLAGS) Main.cpp

Util.o: Util.hpp Util.cpp
	$(CC) $(CFLAGS) Util.cpp

Heap.o: Heap.hpp Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp

clean	:
		rm *.o Main.o Heap.o Util.o
