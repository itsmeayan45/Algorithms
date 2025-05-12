#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int value, weight;
};
int compare(const void *a, const void *b)
{
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) ? 1 : -1; 
}
double fractionalKnapsack(int capacity, struct Item items[], int n, double solution[])
{
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++)
    {
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
            solution[i] = 1.0;
        }
        else
        {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            solution[i] = (double)capacity / items[i].weight; 
            break;                                            
        }
    }
    return totalValue;
}
int main()
{
    struct Item items[] = {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 15;
    double solution[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = 0.0; 
    }
    double maxValue = fractionalKnapsack(capacity, items, n, solution);
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    printf("Solution vector (fraction of each item taken):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: %.2f\n", i + 1, solution[i]);
    }

    return 0;
}
