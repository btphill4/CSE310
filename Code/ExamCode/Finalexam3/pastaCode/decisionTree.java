import java.util.*;
public class decisionTree {
	static int activations = 0;
	static int ewc = 0;
	  public static void main(String[] args) {
	    //intro
	    System.out.println("\n\nWelcome to yeet's tool for calculating activation records, array overwrties, and comparisons.");
	    boolean again = true;
	    char treeStyle = 'a';
	    while (again) {
	    System.out.println("To start, please enter how many elements your array will have:");
	    Scanner kb = new Scanner(System.in);
	    int arrayLength = kb.nextInt();
	    int[] array = new int[arrayLength];
	    System.out.println("Great! Now please enter the values in the order they will be placed in the array!");
	    System.out.println("Please note, for decision tree questions with respect to \"a1\", \"a2\", etc, enter the values in\n their sorted order with respect to INDEX -- i.e  \"1\" for a1, etc.");
	    for (int i = 0; i < arrayLength; i++) {
	      int a = kb.nextInt();
	      array[i] = a;
	    }
	    System.out.print("Great! Your array currently looks like this:\n {");    
	    for (int i = 0; i < arrayLength; i++) {
	      if (i != arrayLength -1) System.out.print(array[i] + ", ");
	      else System.out.print(array[i]);
	    }
	    System.out.println("}");

	    System.out.println("Which algorithm would you like to use?");
	    System.out.println("Please enter a character: \n i: interstion sort\n m: mergesort \n q: quicksort");
	    char choice  = kb.next().charAt(0);
	    switch(choice) {
	      case 'i':
	    System.out.println("Would you like a \"classic\" breakdown (c) or decision-tree style breakdown (t)?");
	    System.out.println("Please enter c or t");
	    treeStyle = kb.next().charAt(0);
	      System.out.println("Calling interstion sort...\n\n");
	      if (treeStyle == 'c') insertionSort(array);
	      else treeInsertionSort(array);
	      System.out.println("Activations records pushed to the stack: " + activations);
	      System.out.println("Sorted array: ");
	      printArray(array);
	      break;
	      case 'm':
	    	  
	  	    System.out.println("Would you like a \"classic\" breakdown (c) or decision-tree style breakdown (t)?");
		    System.out.println("Please enter c or t");
		    treeStyle = kb.next().charAt(0);
	    	  
	      System.out.println("Calling mergeSort...\n\n");
	      if (treeStyle == 'c') mergeSort(array, 0, array.length -1);
	      else {
	    	  int[] toBeSorted = new int[array.length];
	 		    for (int i = 0; i < array.length; i++) toBeSorted[i] = 1; //fill the array with 1's
	 		    for (int i = 0; i < toBeSorted.length; i++) {
	 		    	int idx = array[i] - 1;
	 		    	toBeSorted[idx] = i*3;
	 		    }
	 		    String[] mSortStrings = getStringArray(array);
	 		    treeMergeSort(toBeSorted, mSortStrings, 0, toBeSorted.length - 1);
	      }
	      System.out.println("Activations records pushed to the stack: " + activations);
	      System.out.println("Sorted array: ");
	      printArray(array);
	      break;
	      case 'q':
	    	  System.out.println("Would you like a \"classic\" breakdown (c) or decision-tree style breakdown (t)?");
	  	    System.out.println("Please enter c or t");
	  	    treeStyle = kb.next().charAt(0);
	  	      System.out.println("Calling quick sort...\n\n");
	  	      
	  	      if (treeStyle == 'c') {
	  	    	  quickSort(array, 0, array.length - 1);
	  	    	  System.out.println("Sorted array :");
	  	    	  printArray(array);
	  	      }
	  	      else  {
	  	    	 int[] toBeSorted = new int[array.length];
	 		    for (int i = 0; i < array.length; i++) toBeSorted[i] = 1; //fill the array with 1's
	 		    for (int i = 0; i < toBeSorted.length; i++) {
	 		    	int idx = array[i] - 1;
	 		    	toBeSorted[idx] = i*3;
	 		    }
	 		    String[] qSortStrings = getStringArray(array);
	  	    	  treeQuickSort(toBeSorted, qSortStrings, 0, toBeSorted.length - 1);
	  	      }
	    	  
	    //  System.out.println("Calling quicksort...\n\n");
	     // quickSort(array, 0, array.length - 1);
	      System.out.println("Activations records pushed to the stack: " + activations);
	      break;
	      default:
	      System.out.println("Invalid choice! Please restart the program.");
	      return;
	      
	      
	    }
	    System.out.println("I hope this was helpful. Would you like to do this again? Enter 1 for yes, and 2 for no.");
	    int againint = 0;
	    againint = kb.nextInt();
	    if (againint == 1) {
	    	activations = 0;
	    	ewc = 0;
	    }
	    else again = false;
	    }
	  }

	   static void insertionSort(int[] arr) {
	    activations++;
	    int n = arr.length; 
	    int ow = 0;
	        for (int i = 1; i < n; ++i) { 
	            int key = arr[i]; 
	            int j = i - 1; 
	  
	            /* Move elements of arr[0..i-1], that are 
	               greater than key, to one position ahead 
	               of their current position */

	            while (j >= 0) { 
	              System.out.print(arr[j] + " > " + key + "? --> ");
	              if (!(arr[j] > key)) {
	                 System.out.println("No");
	                 break;
	              }
	              else System.out.println("Yes");
	              System.out.print("OVERWRITE #" + (++ow) + " -- arr[" + (j+1) + "] = " + arr[j]);
	                arr[j + 1] = arr[j]; 
	                System.out.println("\nArray state post-overwrite:");
	                printArray(arr);
	                j = j - 1; 
	            } 
	            System.out.print("OVERWRITE #" + ++ow + " -- arr[" + (j+1) + "] = " + key);
	            arr[j + 1] = key; 
	            System.out.println("\nArray state post-overwrite:");
	            printArray(arr);
	        } 
	    }
	   
	   static String[] getStringArray(int[] arr) {
		   String[] stringArray = new String[arr.length];
		    for (int i = 0; i < stringArray.length; i++) {
		    	String toAdd = "a";
		    	toAdd += (i+1);
		    	stringArray[i] = toAdd;
		    }
		    return stringArray;
	   }
	   
	   static void treeInsertionSort(int[] arr) {
		    activations++;
		    int n = arr.length; 
		    //Modify the array so that it will be sorted as according to the user.
		    int[] toBeSorted = new int[arr.length];
		    for (int i = 0; i < arr.length; i++) toBeSorted[i] = 1; //fill the array with 1's
		    for (int i = 0; i < toBeSorted.length; i++) {
		    	int idx = arr[i] - 1;
		    	toBeSorted[idx] = i*3;
		    }
		    String[] stringArray = getStringArray(arr);
		        for (int i = 1; i < n; ++i) { 
		            int key = toBeSorted[i]; 
		            String keyString = stringArray[i];
		            int j = i - 1; 
		  
		            /* Move elements of arr[0..i-1], that are 
		               greater than key, to one position ahead 
		               of their current position */

		            while (j >= 0) { 
		              System.out.print(stringArray[j] + " > " + keyString + "? --> ");
		              if (!(toBeSorted[j] > key)) {
		                 System.out.println("No");
		                 break;
		              }
		              else System.out.println("Yes");
		                toBeSorted[j + 1] = toBeSorted[j]; 
		                stringArray[j+1] = stringArray[j];

		                j = j - 1; 
		            }  
		            toBeSorted[j + 1] = key; 
		            stringArray[j+1] = keyString;
		        }
		    }
	   
	   static void printArray(int[] a) {
	      
	       System.out.print("{");
	    for (int i = 0; i < a.length; i++) {
	      if (i != a.length -1) System.out.print(a[i] + ", ");
	      else System.out.print(a[i]);
	    }
	    System.out.println("}\n");
	    }
	   
	   static void quickSort(int arr[], int low, int high) 
	    { 
		   activations++;
		   System.out.println("quickSort(A, " + low + ", " + high + ")");
	        if (low < high) 
	        { 
	            /* pi is partitioning index, arr[pi] is  
	              now at right place */
	            int pi = partition(arr, low, high); 
	  
	            // Recursively sort elements before 
	            // partition and after partition 
	            quickSort(arr, low, pi-1); 
	            quickSort(arr, pi+1, high); 
	        } 
	    } 
	   static int partition(int arr[], int low, int high) 
	    { 
		   activations++;
		   System.out.println("Partition(A, " + low + ", " + high + ")");
	        int pivot = arr[high];  
	        int i = (low-1); // index of smaller element 
	        for (int j=low; j<high; j++) 
	        { 
	            // If current element is smaller than the pivot 
	        	System.out.println("\tComparison #" + (++ewc) + ": \n\t" + arr[j] + " <= " + pivot + "?");
	            if (arr[j] <= pivot) 
	            { 
	                i++; 
	  
	                // swap arr[i] and arr[j] 
	                System.out.println("Swap " + arr[i] + " with " + arr[j] + " (A[" + i + "] with A[" + j + "])");
	                int temp = arr[i]; 
	                arr[i] = arr[j]; 
	                arr[j] = temp; 
	            } 
	        } 
	  
	        // swap arr[i+1] and arr[high] (or pivot) 
	        int temp = arr[i+1]; 
	        arr[i+1] = arr[high]; 
	        arr[high] = temp; 
	        System.out.println("Swap " + arr[i+1] + " with " + arr[high] + " (A[" + (i+1) + "] with A[" + high + "])");
	  
	        return i+1; 
	    }
	   
	   static void treeQuickSort(int arr[], String[] strs, int low, int high) 
	    { 
		   activations++;
	        if (low < high) 
	        { 
	            /* pi is partitioning index, arr[pi] is  
	              now at right place */
	            int pi = treePartition(arr, strs, low, high); 
	  
	            // Recursively sort elements before 
	            // partition and after partition 
	            treeQuickSort(arr, strs, low, pi-1); 
	            treeQuickSort(arr, strs, pi+1, high); 
	        } 
	    } 
	   static int treePartition(int arr[], String[] strs, int low, int high) 
	    { 
		   activations++;
	        int pivot = arr[high];
	        String pivotString = strs[high];
	        int i = (low-1); // index of smaller element 
	        for (int j=low; j<high; j++) 
	        { 
	            // If current element is smaller than the pivot 
	        	System.out.print("Comparison #" + (++ewc) + ":" );
	        	if (ewc == 1) System.out.print(" (root node) ");
	        	
	        	System.out.println("\n" + strs[j] + " <= " + pivotString + "?");
	            if (arr[j] <= pivot) 
	            { 
	            	System.out.println(" Yes.");
	                i++; 
	  
	                // swap arr[i] and arr[j] 
	                int temp = arr[i]; 
	                arr[i] = arr[j]; 
	                arr[j] = temp; 
	                String tempStr = strs[i];
	                strs[i] = strs[j];
	                strs[j] = tempStr;
	            } 
	            else System.out.println(" No.");
	        } 
	  
	        // swap arr[i+1] and arr[high] (or pivot) 
	        int temp = arr[i+1]; 
	        arr[i+1] = arr[high]; 
	        arr[high] = temp; 
	        String tempStr = strs[i+1];
	        strs[i+1] = strs[high];
	        strs[high] = tempStr;
	        
	  
	        return i+1; 
	    }
	   
	  static void merge(int arr[], int l, int m, int r)
	    {
		  activations++;
		  System.out.println("merge(A, " + l + ", " + m + ", " + r + ")");
	        // Find sizes of two subarrays to be merged
	        int n1 = m - l + 1;
	        int n2 = r - m;
	 
	        /* Create temp arrays */
	        int L[] = new int[n1];
	        int R[] = new int[n2];
	 
	        /*Copy data to temp arrays*/
	        for (int i = 0; i < n1; ++i)
	            L[i] = arr[l + i];
	        for (int j = 0; j < n2; ++j)
	            R[j] = arr[m + 1 + j];
	 
	        /* Merge the temp arrays */
	 
	        // Initial indexes of first and second subarrays
	        int i = 0, j = 0;
	 
	        // Initial index of merged subarry array
	        int k = l;
	        while (i < n1 && j < n2) {
	        	
	        	System.out.print("\tComparison #" + (++ewc) + ": \n\t" + L[i] + " <= " + R[j] + "?");
	            if (L[i] <= R[j]) {
	            	System.out.println(" Yes.");
	                arr[k] = L[i];
	                i++;
	            }
	            else {
	            	System.out.println(" No.");
	                arr[k] = R[j];
	                j++;
	            }
	            k++;
	        }
	 
	        /* Copy remaining elements of L[] if any */
	        while (i < n1) {
	            arr[k] = L[i];
	            i++;
	            k++;
	        }
	 
	        /* Copy remaining elements of R[] if any */
	        while (j < n2) {
	            arr[k] = R[j];
	            j++;
	            k++;
	        }
	    }
	 
	    // Main function that sorts arr[l..r] using
	    // merge()
	   static void mergeSort(int arr[], int l, int r)
	    {
		   activations++;
		   System.out.println("mergeSort(A," + l + ", " + r +")");
	        if (l < r) {
	            // Find the middle point
	            int m =l+ (r-l)/2;
	 
	            // Sort first and second halves
	            mergeSort(arr, l, m);
	            mergeSort(arr, m + 1, r);
	 
	            // Merge the sorted halves
	            merge(arr, l, m, r);
	        }
	    }
	   
		  static void treeMerge(int arr[], String[] strs, int l, int m, int r)
		    {
			  activations++;
			  System.out.println("merge(A, " + l + ", " + m + ", " + r + ")");
		        // Find sizes of two subarrays to be merged
		        int n1 = m - l + 1;
		        int n2 = r - m;
		 
		        /* Create temp arrays */
		        int L[] = new int[n1];
		        String Lstr[] = new String[n1];
		        int R[] = new int[n2];
		        String[] Rstr = new String[n2];
		 
		        /*Copy data to temp arrays*/
		        for (int i = 0; i < n1; ++i) {
		            L[i] = arr[l + i];
		        	Lstr[i] = strs[l + i];
		        }
		        for (int j = 0; j < n2; ++j) {
		            R[j] = arr[m + 1 + j];
		            Rstr[j] = strs[m + 1 + j];
		        }
		 
		        /* Merge the temp arrays */
		 
		        // Initial indexes of first and second subarrays
		        int i = 0, j = 0;
		 
		        // Initial index of merged subarry array
		        int k = l;
		        while (i < n1 && j < n2) {
		        	
		        	System.out.print("\tComparison #" + (++ewc) + ": \n\t" + Lstr[i] + " <= " + Rstr[j] + "?");
		            if (L[i] <= R[j]) {
		            	System.out.println(" Yes.");
		                arr[k] = L[i];
		                strs[k] = Lstr[i];
		                i++;
		            }
		            else {
		            	System.out.println(" No.");
		                arr[k] = R[j];
		                strs[k] = Rstr[j];
		                j++;
		            }
		            k++;
		        }
		 
		        /* Copy remaining elements of L[] if any */
		        while (i < n1) {
		            arr[k] = L[i];
		            strs[k] = Lstr[i];
		            i++;
		            k++;
		        }
		 
		        /* Copy remaining elements of R[] if any */
		        while (j < n2) {
		            arr[k] = R[j];
		            strs[k] = Rstr[j];
		            j++;
		            k++;
		        }
		    }
		 
		    // Main function that sorts arr[l..r] using
		    // merge()
		   static void treeMergeSort(int arr[], String[] strs, int l, int r)
		    {
			   activations++;
			   System.out.println("mergeSort(A," + l + ", " + r +")");
		        if (l < r) {
		            // Find the middle point
		            int m =l+ (r-l)/2;
		 
		            // Sort first and second halvess
		            treeMergeSort(arr, strs, l, m);
		            treeMergeSort(arr, strs, m + 1, r);
		 
		            // Merge the sorted halves
		            treeMerge(arr,strs, l, m, r);
		        }
		    }
	   
}