#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSudoku(u_int8_t sudoku[][9]) {
    if (!sudoku)
        return;
    for (int i = 0; i < 9; i++) {
        if ((i % 3) == 0 && i != 0)
            printf("---------------------\n");
        printf("%d %d %d | %d %d %d | %d %d %d\n", sudoku[i][0], sudoku[i][1],
                sudoku[i][2], sudoku[i][3], sudoku[i][4], sudoku[i][5],
                sudoku[i][6], sudoku[i][7], sudoku[i][8]);
    }
}

int checkForError(u_int8_t sudoku[][9]) {
    if (!sudoku)
        return 1;
    u_int8_t rowValueCount[10] = {}; // Make sure all values are set to 0. 10 long because we use indexes 1 to 9
    u_int8_t columnValueCount[10] = {};
    u_int8_t blockValueCount[10] = {};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // Check rows
            if (sudoku[i][j] != 0) {
                if (rowValueCount[sudoku[i][j]])
                    return 0;
                else
                    rowValueCount[sudoku[i][j]] = 1;
            }

            // Check columns
            if (sudoku[j][i] != 0) {
                if (columnValueCount[sudoku[j][i]])
                    return 0;
                else
                    columnValueCount[sudoku[j][i]] = 1;
            }

            // Check blocks
            u_int8_t digitIndex = (j%3) + (j/3)*9 + (i%3)*3 + (i/3)*27;
            if ((*sudoku)[digitIndex] != 0) {
                if (blockValueCount[(*sudoku)[digitIndex]])
                    return 0;
                else
                    blockValueCount[(*sudoku)[digitIndex]] = 1;
            }
        }

        memset(rowValueCount, 0, 10);
        memset(columnValueCount, 0, 10);
        memset(blockValueCount, 0, 10);
    }

    return 1;
}

int solve(u_int8_t sudoku[][9]) {
    if (!sudoku)
        return 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                for (int k = 0; k < 9; k++) {
                    sudoku[i][j] += 1;
                    if (checkForError(sudoku)) {
                        if (solve(sudoku))
                            break;
                    }
                    if (k == 8) {
                        sudoku[i][j] = 0;
                        return 0;
                    }
                }
            }
            if (i == 8 && j == 8 && sudoku[i][j] == 0)
                return 0;
        }
    }

    return 1;
}

int main()
{
    FILE* fp;
    fp = fopen("./sudoku.txt", "r");
    if (fp) {
        u_int8_t sudoku[9][9];
        size_t size = 18;
        char* fileLine = malloc(sizeof *fileLine * size);
        if (!fileLine)
            return -1;
        for (int i = 0; i < 9; i++) {
            getline(&fileLine, &size, fp);
            sscanf(fileLine, "%hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu", &sudoku[i][0],
                    &sudoku[i][1], &sudoku[i][2], &sudoku[i][3], &sudoku[i][4],
                    &sudoku[i][5], &sudoku[i][6], &sudoku[i][7], &sudoku[i][8]);
        }
        free(fileLine);
        fclose(fp);

        printSudoku(sudoku);
        printf("\n");
        if (solve(sudoku)) {
            printSudoku(sudoku);

            fp = fopen("./solution.txt", "w+");
            if (fp) {
                for (int i = 0; i < 9; i++) {
                    if ((i % 3) == 0 && i != 0)
                        fprintf(fp, "---------------------\n");
                    fprintf(fp, "%d %d %d | %d %d %d | %d %d %d\n", sudoku[i][0], sudoku[i][1],
                            sudoku[i][2], sudoku[i][3], sudoku[i][4], sudoku[i][5],
                            sudoku[i][6], sudoku[i][7], sudoku[i][8]);
                }
                fclose(fp);
            }

        }
        else
            printf("No solution found.\n");
    }

    return 0;
}
