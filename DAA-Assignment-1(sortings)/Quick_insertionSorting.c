#include <stdio.h>
#include <stdio.h>
#include <time.h>




int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // Selecting last element as pivot 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) { 
        if (arr[j] < pivot) { 
            i++; 
            // Swapping arr[i] and arr[j] 
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        } 
    } 
  
    // Swapping arr[i + 1] and arr[high] 
    int temp = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = temp; 
  
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

// Insertion sort function
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    
    int n, i;
  int arr[10000]; //array of size 100 (can be changed to accommodate different n values)

  // n values: 5, 10, 50, 90, 95, 100
  n = 100;
  srand(time(0)); // seed the random number generator with the current time
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 1000; //generates random numbers between 0 and 999
  }

    clock_t start, end;

    // Calculate time complexity for merge sort
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    double time_taken_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Quick sort: %f\n", time_taken_merge);

    // Calculate time complexity for insertion sort
    start = clock();
    insertionSort(arr, n);
    end = clock();
    double time_taken_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Insertion sort: %f\n", time_taken_insertion);



}