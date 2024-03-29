
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
    int deletedKey = 0;

    //project 2 variables
    

    //command line input loop
    while(1)
    {
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
                mainHeap->setSize(n);
                for(int i = 1; i <= n; i++) 
                {
                    input >> w;
	                mainHeap->H[i].key = w;
	                //mainHeap->size++;
                    //mainHeap->heapifyCount++;
                    //cout << endl << mainHeap->size;
                    
                }
                mainHeap->buildMinHeap(mainHeap);
                if(f==1)
                {
                    cout << "Number of Heapify calls: " << mainHeap->heapifyCount << endl;
                    mainHeap->heapifyCount = 0;
                }
                break;
                
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
                    printf("Error: cannot write\n");

                    break;
                }

                //if file cannot be opened
                //jfile >> temp2;
                if(jfile.fail())
                {
                     
                     printf("Error: cannot write\n");
                     //printf("Error: cannot open file for writing\n");
                     break;
                }

                //size check
                if(mainHeap->size == 0)
                {
                    //printf("Error: heap is NULL\n");
                    printf("Error: cannot write\n");
                    break;
                }

                //else write
                else
                {
                    //printf("Error: cannot open file for writing\n");.
                    printf("Error: cannot write\n");
                    break;
                }
                break;
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
                if (mainHeap->size == 0)
                {
                    printf("Error: heap is NULL or empty\n");
                    break;
                }

                //else does extractMin(mainHeap)
                else
                {
                    
                    deletedKey = mainHeap->extractMin(mainHeap);
                    cout << "Deleted key: " << deletedKey << endl;
                    if(f==1)
                    {
                        if(mainHeap->heapifyCount == 0)
                        {
                            cout << "Number of Heapify calls: " << 1 << endl;
                        }
                        else
                        cout << "Number of Heapify calls: " << mainHeap->heapifyCount << endl;
                        mainHeap->heapifyCount = 0;
                    }
                    break;
                    
                }
                
                //code
                
                break;    

            //Inserts the element into the heap
            case 'i':
            case 'I':
                //printf("COMMAND: %c %d\n", c, n);
                //int n = value 

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

                //else Dynamically allocates memory for an ELEMENT, 
                //sets its key field to value, and inserts it
                //to the heap pointed to by heap
                else
                {
                    mainHeap->insert(mainHeap, n);
                    break;
                }
                //code
                break;  
            
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
                if (mainHeap->size == mainHeap->capacity)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //if index is not within interval [1, heap->size]
                if(n <= 0 && n <= mainHeap->size)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                //if n >= heap->H[index]->key
                if(f >= mainHeap->H[n].key)
                {
                    printf("Error: invalid call to DecreaseKey\n");
                    break;
                }
                else
                {
                    //decrese the key of mainHeap->H[index(n)] 
                    mainHeap->decreaseKey(mainHeap, n, f);
                    break;
                }
                
                break;  
            
            default: 
                cout << "Please Enter correct Input" << endl;
                break;
        }
        //segfault fix
        if(initalized == true)
        {
        mainHeap->heapifyCount = 0;
        }
    }//end while
exit(0);
}//end main
//=============================================================================