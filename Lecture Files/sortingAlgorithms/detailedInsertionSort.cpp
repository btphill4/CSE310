#include <iostream>

using namespace std;

//Prints out element wise comparisons
int count = 0;
/* Function to sort an array using insertion sort*/
void inversionCounter(int arr[], int n){
    int b, a;
    int inversion=0;
    for (int a = 0; a < n; a++)
    {
        b=a+1;
        while(b<n){
            if(arr[a]>arr[b]){
                inversion++;
                cout <<"<"<<a+1<<","<<b+1<<"> " ;
            }
            b++;
        }
    }
    cout <<"\n" ;
    cout<<"Total inversions = "<<inversion<<"\n";
    cout<<"Running time of insertion sort is BigTheta("<<n<<" + "<<inversion<<").\n";
}
void insertionSort(int arr[], int n)
{

    int j, key, i;
    //int inversion=0;
    for (j = 1; j < n; j++)
    {
        //printArray(arr,n);
        
        key = arr[j];
        i = j - 1;

        /* For print the iterations and comparisions */
        cout << arr[j] << ">" << key << endl;       //checks if element j is larger than key (key = arr[i])
        cout << "Iteration: " << i << " " << endl;  //prints the iteration
        for(int x = 0; x < 5; x++)
        {
            cout << arr[x] << ", ";                 //loops to print the current array 
        }

        /* Move elements of arr[0..j-1], that are
        greater than key, to one position ahead
        of their current position */

        while (i >= 0 && arr[i] > key)
        {   
                /* For print the iterations and comparisions */
            cout << arr[j] << ">" << key << endl;       //checks if element j is larger than key (key = arr[i])
            cout << "Iteration: " << i << " " << endl;  //prints the iteration
            for(int x = 0; x < 5; x++)
            {
                cout << arr[x] << ", ";                 //loops to print the current array 
            }
            count++;
            cout<< count << " "<<arr[i]<<">"<<key<<"\n";
            arr[i + 1] = arr[i];
            //inversion++;
            //cout<<"Inversion = "<<inversion<<"\n"; //if you want to see when inversions are made
            i = i - 1;

        }
        if(i>=0){   //Avoids printing out of bound comparisons. Since the while loop has 2 conditions we need this 2nd cout.
        /* For print the iterations and comparisions */
        cout << arr[j] << ">" << key << endl;       //checks if element j is larger than key (key = arr[i])
        cout << "Iteration: " << i << " " << endl;  //prints the iteration
        for(int x = 0; x < 5; x++)
        {
            cout << arr[x] << ", ";                 //loops to print the current array 
        }
            count++;
            cout<< count << " " <<arr[i]<<">"<<key<<"\n";
        }
        arr[i + 1] = key;
    }
    //cout<<"Total inversions = "<<inversion<<"\n";
    //cout<<"Running time of insertion sort is BigTheta("<<n<<" + "<<inversion<<").\n";
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Driver code */
int main()
{
    int arr[] = { 11,15,14,13,12}; //These are test inputs
    //int arr[] = { 3,2,1,5,4}; //These are test inputs
    //int arr[] = { 1,5,4,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    inversionCounter(arr,n);
    insertionSort(arr, n);
    printArray(arr, n);


    return 0;
}