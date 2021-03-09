// C++ program to Count Inversions
// in an array
#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
            {
				inv_count++;
                cout << "Inversions: " << inv_count << endl << "("<<arr[i] << ", " << arr[j] << ")" << endl;
            }
	return inv_count;
}

// Driver Code
int main()
{
	int arr[] = { 8,4,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " Number of inversions are "
		<< getInvCount(arr, n) << endl;
	return 0;
}

