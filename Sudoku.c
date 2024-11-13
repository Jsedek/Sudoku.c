#include <stdio.h>
#include <stdbool.h>

#define N 9

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

void solveSudoku(int grid[N][N]) {
    int row, col;
    bool empty = true;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                empty = false;
                break;
            }
        }
        if (!empty) break;
    }

    if (empty) {
        for (int r = 0; r < N; r++) {
            for (int d = 0; d < N; d++) {
                printf("%d ", grid[r][d]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            solveSudoku(grid);
            grid[row][col] = 0;
        }
    }
}

void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            printf("%d ", grid[r][d]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N] = {0};

    printf("Wypełnij 2 pola Sudoku (podaj rząd, kolumnę i wartość):\n");
    for (int i = 0; i < 2; i++) {
        int row, col, num;
        printf("Pole %d:\n", i + 1);
        printf("Rząd (0-8): ");
        scanf("%d", &row);
        printf("Kolumna (0-8): ");
        scanf("%d", &col);
        printf("Wartość (1-9): ");
        scanf("%d", &num);

        if (row >= 0 && row < N && col >= 0 && col < N && num >= 1 && num <= 9) {
            grid[row][col] = num;
        } else {
            printf("Błędne dane. Spróbuj ponownie.\n");
            i--;
        }
    }

    printf("Zainicjowana plansza Sudoku:\n");
    printGrid(grid);

    printf("Wszystkie możliwe rozwiązania Sudoku:\n");
    solveSudoku(grid);

    return 0;
}
