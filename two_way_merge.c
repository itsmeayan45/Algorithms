#include <stdio.h>

void merge(int a[], int b[], int m, int n)
{
    int c[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        { 
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (i < m)
    {
        c[k++] = a[i++];
    }
    while (j < n)
    {
        c[k++] = b[j++];
    }
    printf("\nThe sorted array is:\n");
    for (int l = 0; l < k; l++)
    {
        printf("%d ", c[l]);
    }
    printf("\n");
}

int main()
{
    int m, n;
    printf("Enter the size of the first array:\n");
    scanf("%d", &m);
    int a[m];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of the second array:\n");
    scanf("%d", &n);
    int b[n];
    printf("Enter the elements of the second array:\n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &b[j]);
    }

    printf("\nThe first sorted list is:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nThe second sorted list is:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", b[j]);
    }

    merge(a, b, m, n);
}
