#include <stdio.h>
int rbinarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1; 
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
        return mid; 
    }
    if (arr[mid] > target)
    {
        return rbinarySearch(arr, left, mid - 1, target);
    }
    return rbinarySearch(arr, mid + 1, right, target);
}

int main()
{
    int x, n;
    printf("Enter the size of the array :\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("array that you have entered is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\nEnter a number you want to search: ");
    scanf("%d", &x);
    int result = rbinarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
}
