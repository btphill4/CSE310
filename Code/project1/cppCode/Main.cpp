//=============================================================================
//The following is a partial program that calls the above program.
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "Util.hpp"
#include "Heap.hpp"
//testing
int main()
{
    FILE * ifile;
    // variables for the parser...
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
                HEAP heap;
                heap.intialize(f);
                break;
            
            //reading file
            case 'r':
            case 'R': 
                printf("COMMAND: %c\n", c);
                ifile = fopen("HEAPinput.txt", "r");
                
                if (!ifile)
                {

                }
                fscanf(ifile, "%d", &n);

            //printing the heap
            case 'p':
            case 'P':
                printf("COMMAND: %c\n", c);

            //writing to the heap
            case 'w':
            case 'W':  
                printf("COMMAND: %c\n", c);
                

            default: break;
        }
    }
exit(0);
}
//=============================================================================