#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int R[n1],L[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%3d",arr[i]);
    }
    printf("\n");
}
int main()
{
    int i,size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Your enterted array is:\n");
    printarray(arr,size);
    int l=0;
    int r=size;
    mergesort(arr,l,r);
    printf("Applying merge sort,the sorted array is:\n");
    printarray(arr,size);
}