EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of the shell variable EXEC which is run.
# run depends on the files main.o util.o heap.o
$(EXEC): main.o util.o heap.o
# run is created by the command g++ -o run main.o util.o
#note that the tab before $(CC) is REQUIRED
	$(CC) -o $(EXEC) main.o util.o heap.o

# main .o depends on the files main.h main.cpp
main.o: main.hpp main.cpp
# main.o is created by the g++ -c -Wall main.cpp
# note that the TAB before $(CC) is REQUIRED...
	$(CC) $(CFLAGS) main.cpp

util.o: util.hpp util.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o: heap.hpp heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean	:
		rm *.o main.o heap.o util.o
