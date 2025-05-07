#include <stdio.h>
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int x,n;
    printf("Enter the size of the array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("array that you have entered is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\nEnter a number you want to search: ");
    scanf("%d",&x);
    int result = binarySearch(arr, 0, n - 1, x);
   if(result == -1) printf("Element is not present in array");
   else printf("Element is present at index %d",result);

}