#include <stdio.h>
#include <stdarg.h>

void read_console() {
    char text[256];
    int counter = 0;
    printf("Enter text. Use enter to exit\n");
    do {
        text[counter]=getchar();
        counter++;
    } while (text[counter - 1] != '\n' && counter < 256);
    printf("%s", text);
}

void print_console(char* str, ...) {
    va_list argruments;
    va_start(argruments, str);
    char* tempstr = str;
    while (*tempstr != 0) {
        if (*tempstr != '%') printf("%c", *tempstr);
        if (*tempstr == '%') {
            if (*(tempstr+1) == 'd') {
                int arg_int = va_arg(argruments, int);
                printf("\033[32m%d\033[0m", arg_int);
            }
            if (*(tempstr+1) == 's') {
                char* arg_str = va_arg(argruments, char*);
                printf("\033[31m%s\033[0m", arg_str);
            }
            if (*(tempstr+1) == 'f') {
                double arg_float = va_arg(argruments, double);
                printf("\033[34m%f\033[0m", arg_float);
            }
            tempstr++;
        }
        tempstr++;
    }
}

void printsudoku(int sudoku[][9]) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            printf("%d\t", sudoku[y][x]);
        }
        printf("\n");
    }
}

void sudoku() {
    int source_sudoku[9][9] = {
        {5, 3, -1, -1, 7, -1, -1, -1},
        {6, -1, -1, 1, 9, 5, -1, -1, -1},
        {-1, 9, 8, -1, -1, -1, -1, 6, -1},
        {8, -1, -1, -1, 6, -1, -1, -1, 3},
        {4, -1, -1, 8, -1, 3, -1, -1, 1},
        {7, -1, -1, -1, 2, -1, -1, -1, 6},
        {-1, 6, -1, -1, -1, -1, 2, 8, -1},
        {-1, -1, -1, 4, 1, 9, -1, -1, 5},
        {-1, -1, -1, -1, 8, -1, -1, 7, 9}
    };
    printsudoku(source_sudoku);
//    FILE *fp;
//    int c;
//    fp = fopen("/home/raptor/wpo2/sudoku.txt", "r");
//    if (fp) {
//        while ((c=fgetc(fp)) != EOF) {
//            printf("%c", (char)c);
//        }
//        fclose(fp);
//    } else {
//        printf("File not found.");
//    }
}

int main() {
//    print_console("%s: %d + %f\n", "getal", 20, 3.4);
    //read_console();
    sudoku();
    return 0;
}
