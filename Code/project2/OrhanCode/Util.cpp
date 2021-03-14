#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "Heap.h"
using namespace std;


int nextCommand(int *n, int *f)
{
    char c;
    while(1){
        scanf("%c", &c);
        //input is empty, null, or tab
        if (c == ' ' || c == '\t' || c == '\n')
        {
            continue;
        }

        //S input, Stops the program
        if (c == 'S' || c == 's')
        {
            break;
        }
        
        //C input, creates heap of size n
        if (c == 'C' || c == 'c')
        {
            scanf("%d", n);
            break;
        }

        //P input, prints the heap
        if (c == 'P' || c == 'p')
        {
            break;
        }

        //R input, read input from HEAPinput.txt
        if (c == 'R' || c == 'r')
        {
            scanf("%d", f);
            break;
        }

        //W input, writes to output files HEAPoutput.txt
        if (c == 'W' || c == 'w')
        {
            break;
        }
        
        //end project1 stuff
        //=======================================================//

        //PROJECT2 STUFF
        //D input, deletes minimum element and writes out deleted element
        if (c == 'D' || c == 'd')
        {
            scanf("%d", f);
            break;
        }

        //I input, insert key to ELEMENT[]
        if (c == 'I' || c == 'i')
        {
            scanf("%d", n);
            break;
        }

        //K input, decrease key
        if (c == 'K' || c == 'k')
        {
            //scan for index
            scanf("%d", n);

            //scan for value
            scanf("%d", f);
            break;
        }
        
        printf("Warning in nextCommand: invalid input\n");
        break;
        
    }//end while()
    return c;
}// end int nextCommand()

