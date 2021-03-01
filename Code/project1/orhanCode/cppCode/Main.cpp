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

using namespace std;
int main()
{
    std::ifstream ifile("input.txt");
    std::ifstream jfile("HEAPinput.txt");
    std::ifstream input("HEAPinput.txt");
    bool initalized = false;
    // variables for the parser....
    std::string temp2;
    //char *temp;
    HEAP* cheap;
    char c;
    int w;
    //int i, v;
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
                initalized = true;
                break;
            
            //read command
            case 'r':
            case 'R': 
                printf("COMMAND: %c\n", c);
                
                if(!initalized)
                {
                    cout << "Error: heap overflow\n";
                    break;
                }

                input >> n;
                if (!input)
                {
                   printf("Error: cannot open file for reading\n");
                   break;
                }
                if(cheap == NULL || cheap->capacity < n)
                {
                      std::cout << "Error: heap overflow\n";
                      break;
                }
                //cheap->setSize(n);
                for(int i = 1; i<= cheap->getSize(); i++)
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
                if(!initalized)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }

                if(cheap->size == 0)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }
                cheap->heapPrint(cheap);
                break;

            //write command
            case 'w':
            case 'W':  
                printf("COMMAND: %c\n", c);
                if(!initalized)
                {
                     printf("Error: cannot open file for writing\n");

                    break;
                }

                //jfile >> temp2;
                if(jfile.fail())
                {
                     printf("Error: cannot open file for writing\n");
                     break;
                }

                if(cheap->size == 0)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }
                else
                {
                    printf("Error: cannot open file for writing\n");
                    break;
                }
                

            default: break;
        }
    }
exit(0);
}
//=============================================================================