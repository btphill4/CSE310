/** 
 * Author: Brandon Phillips
 * Function: This is the main function that uses the util.h/.cpp
 * heap.h/.cpp to take command line input and do various functions to a heap object
*/
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
    //Files for reading and writing
    std::ifstream ifile("input.txt");
    std::ifstream jfile("HEAPinput.txt");
    std::ifstream input("HEAPinput.txt");

    //heap initialize check for while()
    bool initalized = false;

    // variables for the parser....
    std::string temp2;
    //char *temp;
    HEAP* mainHeap;
    char c;
    int w;
    //int i, v;
    int n, f;

    //project 2 variables
    

    //command line input loop
    while(1)
    {
        int heapifyCounter = 0;
        c = nextCommand(&n, &f);
        switch (c) 
        {
            //S input, stops the while loop
            case 's':
            case 'S': 
                //printf("COMMAND: %c\n", c); 
                exit(0);
            
            //C input: Creates a heap object and sets initalized to true
            case 'c':
            case 'C': 
                //printf("COMMAND: %c %d\n", c, n);
                mainHeap = mainHeap->initialize(n);
                initalized = true;
                break;
            
            //R input: reads from a heap from a file and adds it to the heap object
            case 'r':
            case 'R': 
                //printf("COMMAND: %c %d\n", c, f);
                
                //initalize check
                if(!initalized)
                {
                    cout << "Error: heap overflow\n";
                    break;
                }
                
                //set input
                input >> n;

                //if input cannot be opened
                if (!input)
                {
                   printf("Error: cannot open file for reading\n");
                   break;
                }

                //null and size check
                if(mainHeap == NULL || mainHeap->capacity < n)
                {
                      std::cout << "Error: heap overflow\n";
                      break;
                }

                //write to the heap
                //mainHeap->setSize(n);
                for(int i = 1; i<= mainHeap->getSize(); i++)
                {
                    input >> w;
                    ELEMENT *keyPtr = new ELEMENT();
                    keyPtr->key = w;
                    //std::cout << w << "\n";                   //Testing purposes
                    mainHeap->H[i] = *keyPtr;
                    //std::cout << mainHeap->H[i].key << "\n";  //Testing purposes
                    
                    //Call to build heap
                    heapifyCounter = mainHeap->buildMinHeap(mainHeap);

                    //increments the heapSize with each added element
                    mainHeap->size++;
                }
                //if f = 1, print number of Heapify Calls
                if(f == 1)
                {
                    cout << "Number of Heapify calls: " << heapifyCounter << endl;
                    break;
                }
                break;

            //print command
            case 'p':
            case 'P':
                //printf("COMMAND: %c\n", c);

                //initalize check
                if(!initalized)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }

                if(mainHeap == NULL)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }
                //size check
                /*if(mainHeap->size == 0)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }*/
                //print function
                mainHeap->heapPrint(mainHeap);
                break;

            //W: input, writes the array and commands to a file
            case 'w':
            case 'W':  
                //printf("COMMAND: %c\n", c);

                //initalize check
                if(!initalized)
                {
                     printf("Error: cannot open file for writing\n");

                    break;
                }

                //if file cannot be opened
                //jfile >> temp2;
                if(jfile.fail())
                {
                     printf("Error: cannot open file for writing\n");
                     break;
                }

                //size check
                if(mainHeap->size == 0)
                {
                    printf("Error: heap is NULL\n");
                    break;
                }

                //else write
                else
                {
                    printf("Error: cannot open file for writing\n");
                    break;
                }
            //end project 1 stuff

//========================================================================//

            //PROJECT 2 STUFF
            //D, deletes the minimum element and writes it to terminal
            case 'd':
            case 'D':
                //printf("COMMAND: %c\n", c);

                //initalize check
                if(!initalized)
                {
                    printf("Error: heap is NULL or empty\n");
                    break;
                }
                //heap is null or size is 0 
                //THIS BREAKS CAUSE SIZE ISSUES
                if (mainHeap->size == 0)
                {
                    printf("Error: heap is NULL or empty\n");
                    break;
                }

                //else does extractMin(mainHEap)
                else
                {
                    //wrong i think
                    //mainHeap->extractMin(mainHeap);
                    break;
                }
                //code
                break;    

            case 'i':
            case 'I':
                //printf("COMMAND: %c %d\n", c, n);

                if(!initalized)
                {
                    printf("Error: heap is NULL or full\n");
                    break;
                }
                //heap is null or size is 0
                if (mainHeap->size == mainHeap -> capacity)
                {
                    printf("Error: heap is NULL or full\n");
                    break;
                }

                //else adds the element
                else
                {
                    //wrong
                    //mainHeap->insert(n)
                    break;
                }
                //code
                break;  
            
            //unposted 4
            //K, decreases the key of heap->H[index]
            case 'k':
            case 'K':
                //printf("COMMAND: %c\n", c);

                if(!initalized)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //heap is null or size is 0
                if (mainHeap->size == mainHeap -> capacity)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //if index is not within interval [1, heap->size]
                if(n != mainHeap->size)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //if n >= heap->H[index]->key
                if(n >= mainHeap->H->key)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                else
                {
                    //probably wrong
                    //mainHeap->decreaseKey(mainHeap, mainHeap->size, n );
                    break;
                }
                
                //code

                break;  
            
            default: 
                cout << "Please Enter correct Input" << endl;
                break;
        }
    }//end while
exit(0);
}//end main
//=============================================================================