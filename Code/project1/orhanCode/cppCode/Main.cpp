//=============================================================================
//The following is a partial program that calls the above program.
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "Util.hpp"
#include "Heap.hpp"
#include <iostream>
#include <fstream>
#include <string>
//testing
int main()
{
    std::ifstream ifile ("input.txt");
    std::ifstream jfile ("HEAPinput.txt");
    // variables for the parser....
    std::string temp2;
    char *temp;
    HEAP cheap;
    HEAP* heapPtr;
    char c;
    int i, v;
    int n, f;
    while(1)
    {
        
        c = nextCommand(&n, &f);
        switch (c) 
        {
            //stopping the program
            case 's':
            case 'S': 
                printf("COMMAND: %c\n", c); 
                exit(0);
            
            //Creating the heap
            case 'c':
            case 'C': 
                printf("COMMAND: %c %d\n", c, n);
                heapPtr = cheap.initialize(n);

                break;
            
            //reading file
            case 'r':
            case 'R': 
                printf("COMMAND: %c\n", c);
                
                if (!jfile)
                {
                   printf("Error: cannot open file for reading\n");
                }
                else
                {
                    
                }
                getline(jfile, temp2);

            //printing the heap
            case 'p':
            case 'P':
                printf("COMMAND: %c\n", c);
                cheap.heapPrint(heapPtr);

            //writing to the heap
            case 'w':
            case 'W':  
                printf("COMMAND: %c\n", c);
                //use ofstream

            default: break;
        }
    }
exit(0);
}
//=============================================================================