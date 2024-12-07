#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N];
int count = 0;

bool is_safe(int row, int col) {
    int i, j;
    /* Check this row on left side */ 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solve_n_queens(int col) {
    /* base case: If all queens are placed then increment count */
    if (col >= N) {
        count++;
        return;
    }

    /* Consider this column and try placing this queen in all rows one by one */
    for (int i = 0; i < N; i++) {
        /* Check if the queen can be placed on board[i][col] */
        if (is_safe(i, col)) {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;

            /* recur to place rest of the queens */
            solve_n_queens(col + 1);

            /* If placing queen in board[i][col] doesn't lead to a solution then remove queen from board[i][col] */
            board[i][col] = 0;
        }
    }
}

int main() {
    solve_n_queens(0);
    printf("%d solutions found", count);
    return 0;
}
