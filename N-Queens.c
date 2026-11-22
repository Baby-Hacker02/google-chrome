#include <stdio.h>

#define N 4

int board[N][N];

int isSafe(int row, int col)
{
    int i, j;

    // Check same column
    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return 0;
    }

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return 0;
    }

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

int solve(int row)
{
    int col;

    if (row == N)
        return 1;

    for (col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solve(row + 1))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Solving %d-Queen problem...\n\n", N);

    if (solve(0))
    {
        printf("Solution:\n");

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("%d ", board[i][j]);
            }

            printf("\n");
        }
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}
