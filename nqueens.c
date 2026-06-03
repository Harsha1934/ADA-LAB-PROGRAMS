#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isSafe(int row, int col, int n, int board[n][n]) {
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return 0;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return 0;
    }
    return 1;
}
void printBoard(int n, int board[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(board[i][j] ? "Q " : ". ");
        }
        printf("\n");
    }
    printf("\n");
}
void solve(int row, int n, int board[n][n]) {
    if (row == n) {
        printBoard(n, board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n, board)) {
            board[row][col] = 1;
            solve(row + 1, n, board);
            board[row][col] = 0;
        }
    }
}
int main() {
    int n = 4;
    int board[4][4];

    memset(board, 0, sizeof(board));

    solve(0, n, board);

    return 0;
}
