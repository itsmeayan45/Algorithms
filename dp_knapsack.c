#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int cap, int wt[], int p[], int size)
{
    int dp[size + 1][cap + 1];

    
    for (int i = 0; i <= size; i++)
    {
        for (int w = 0; w <= cap; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            { 
                dp[i][w] = max(p[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[size][cap];
}

int main()
{
    int size;
    printf("Enter the number of objects:\n");
    scanf("%d", &size);

    int p[size];
    int wt[size];

    printf("Enter the profit of items:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &p[i]); 
    }

    printf("Enter the weight of the corresponding profits:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &wt[i]); 
    }

    printf("\n");
    printf("Enter the capacity of the bag:\n");
    int cap;
    scanf("%d", &cap);

    int result = knapsack(cap, wt, p, size);
    printf("\nResult is:%d\n", result);

    return 0;
}
