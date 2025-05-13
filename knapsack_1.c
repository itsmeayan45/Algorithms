#include <stdio.h>

int knapsack(int capacity, int weights[], int values[], int n, int solution[])
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    if (weights[n - 1] > capacity)
    {
        
        return knapsack(capacity, weights, values, n - 1, solution);
    }
    else
    {
        int includedSolution[100] = {0};
        int includeValue = values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1, includedSolution);
        int excludedSolution[100] = {0};
        int excludeValue = knapsack(capacity, weights, values, n - 1, excludedSolution);
        if (includeValue > excludeValue)
        {
            for (int i = 0; i < n - 1; i++)
            {
                solution[i] = includedSolution[i];
            }
            solution[n - 1] = 1;
            return includeValue;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                solution[i] = excludedSolution[i];
            }
            solution[n - 1] = 0;
            return excludeValue;
        }
    }
}

int main()
{
    int n, capacity;
    int weights[100], values[100];
    int solution[100] = {0};
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }
    int maxValue = knapsack(capacity, weights, values, n, solution);
    printf("The maximum value that can be carried in the knapsack is: %d\n", maxValue);
    printf("Items selected (1 means included, 0 means excluded):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: %d\n", i + 1, solution[i]);
    }
    return 0;
}
