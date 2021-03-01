#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "Heap.h"
using namespace std;

/** 
 * S stops
 * C n creates heap of size n
 * R reads from HEAPinput.txt first integer n, then the following integers
 *   dynamically allocating memory for an ELEMENT, sets it to key and pointer
 *   heap->Elements[j] points to this element
 * P prints the heap to console(same format as HEAPinput.txt)
 * W writes the heap to HEAPoutput.txt
*/

//=============================================================================
/** 
 * gets the next input of the command lines and returns it to the main
*/

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
            //cout << "COMMAND: " << c << endl;
            
            break;
        }
        
        //C input, creates heap of size n
        if (c == 'C' || c == 'c')
        {
            scanf("%d", n);
            //HEAP::initalize(&n);

            //cout << "COMMAND: " << c << " " << n <<endl;

            break;
        }

        //P input, prints the heap
        if (c == 'P' || c == 'p')
        {
            
            //HEAP::heapPrint()
            //cout << "COMMAND: " << c << endl;

            break;
        }

        //R input, read input from HEAPinput.txt
        if (c == 'R' || c == 'r')
        {
            //cout << "COMMAND: " << c << endl;

            break;
        }

        //W input, writes to output files HEAPoutput.txt
        if (c == 'W' || c == 'w')
        {
            //cout << "COMMAND: " << c << endl;

            break;
        }

        
    }
    return c;
} 

