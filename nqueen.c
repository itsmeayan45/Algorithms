#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];


int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

// main algorithm starts
int solveNQueen(int row, int n)
{
    if (row == n)
    {
        // Print the solution
        printf("\nSolution Found:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                    printf("1 ");
                else
                    printf("0 ");
            }
            printf("\n");
        }
        return 1; 
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            if (solveNQueen(row + 1, n))
                return 1;
        }
    }
    return 0; 
}

int main()
{
    int n;
    printf("Enter number of queens (n): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Please enter n between 1 and %d\n", MAX);
        return 1;
    }

   
    for (int i = 0; i < n; i++)
        board[i] = -1;

    if (!solveNQueen(0, n))
        printf("No solution exists for %d queens.\n", n);

    return 0;
}
