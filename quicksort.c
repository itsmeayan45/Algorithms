#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (i <= high && arr[i] <= pivot); 

        do
        {
            j--;
        } while (j >= low && arr[j] > pivot); 

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j; 
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quickSort(arr, low, j - 1);  
        quickSort(arr, j + 1, high); 
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1); 
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
