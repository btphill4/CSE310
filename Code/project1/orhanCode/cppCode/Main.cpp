//=============================================================================
//The following is a partial program that calls the above program.
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "Heap.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream ifile("input.txt");
    std::ifstream jfile("HEAPinput.txt");
    std::ifstream input("HEAPinput.txt");
    // variables for the parser....
    std::string temp2;
    char *temp;
    HEAP* cheap;
    char c;
    int w;
    int i, v;
    int n, f;
    while(1)
    {
        c = nextCommand(&n, &f);
        switch (c) 
        {
            //Stop command
            case 's':
            case 'S': 
                printf("COMMAND: %c\n", c); 
                exit(0);
            
            //Create command and set capacity
            case 'c':
            case 'C': 
                printf("COMMAND: %c %d\n", c, n);
                cheap = cheap->initialize(n);
                break;
            
            //read command
            case 'r':
            case 'R': 
                printf("COMMAND: %c\n", c);
                
                if (!input)
                {
                   printf("Error: cannot open file for reading");
                   break;
                }
                input >> n;
                if(cheap == NULL || cheap->size < n)
                {
                      std::cout << "Error: heap overflow\n";
                      break;
                }
                cheap->setSize(n);
                for(int i = 1; i<=n; i++)
                {
                    input >> w;
                    ELEMENT *nElement = new ELEMENT();
                    nElement->key = w;
                    //std::cout << w << "\n";
                    cheap->H[i] = *nElement;
                    //std::cout << cheap->H[i].key << "\n";

                }
                //getline(input.open, temp2);
                break;

            //print command
            case 'p':
            case 'P':
                printf("COMMAND: %c\n", c);
                if(cheap->size == 0)
                {
                    printf("Error: heap is NULL");
                    break;
                }
                cheap->heapPrint(cheap);
                break;

            //write command
            case 'w':
            case 'W':  
                printf("COMMAND: %c\n", c);
                if(cheap->size == 0)
                {
                    printf("Error: heap is NULL");
                    break;
                }
                if(!jfile)
                {
                     printf("Error: cannot open file for writing");
                     break;
                }

            default: break;
        }
    }
exit(0);
}
//=============================================================================