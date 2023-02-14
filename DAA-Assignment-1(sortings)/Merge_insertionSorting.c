#include <stdio.h>
#include <stdio.h>
#include <time.h>


// Merge sort function
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to merge two subarrays
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
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
  int arr[100]; //array of size 100 (can be changed to accommodate different n values)

  // n values: 5, 10, 50, 90, 95, 100
  n = 100;
  srand(time(0)); // seed the random number generator with the current time
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 1000; //generates random numbers between 0 and 999
  }

    clock_t start, end;

    // Calculate time complexity for merge sort
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    double time_taken_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Merge sort: %f\n", time_taken_merge);

    // Calculate time complexity for insertion sort
    start = clock();
    insertionSort(arr, n);
    end = clock();
    double time_taken_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Insertion sort: %f\n", time_taken_insertion);



}