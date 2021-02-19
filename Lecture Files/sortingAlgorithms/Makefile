#MakeFile example

#target: dependency1 dependency2 ...
#	<tab> command

#NOTE: remember to add the TAB character before the command part

#Typing 'make' will invoke the first target entry in the file

#declare the variable as CC will tell type of compiler
CC=g++

CFLAGS=-c -Wall

#this target will compile all the files "make all"
all: detailedInsertionSort detailedMergeSort detailedQuickSort numberOfInversions

detailedInsertionSort: detailedInsertionSort.cpp 
	$(CC) detailedInsertionSort.cpp -o detailedInsertionSort

detailedInsertionSort.o: detailedInsertionSort.cpp
	$(CC) $(CFLAGS) detailedInsertionSort.cpp

detailedMergeSort: detailedMergeSort.cpp 
	$(CC) detailedMergeSort.cpp -o detailedMergeSort

detailedMergeSort.o: detailedMergeSort.cpp
	$(CC) $(CFLAGS) detailedMergeSort.cpp

detailedQuickSort: detailedQuickSort.cpp 
	$(CC) detailedQuickSort.cpp -o detailedQuickSort

detailedQuickSort.o: detailedQuickSort.cpp
	$(CC) $(CFLAGS) detailedQuickSort.cpp

numberOfInversions: numberOfInversions.cpp 
	$(CC) numberOfInversions.cpp -o numberOfInversions

numberOfInversions.o: numberOfInversions.cpp
	$(CC) $(CFLAGS) numberOfInversions.cpp

clean:
	rm -rf *o detailedInsertionSort detailedMergeSort detailedQuickSort numberOfInversions


#this target will compile when "make compile" is executed
#compile:
#	g++ encode.cpp -o project1
