#include <stdio.h>
#include <stdarg.h>

void print_console(char* text, ...) {
    va_list argruments;

}

int main() {
    char text[256];
    int counter = 0;
    printf("Enter text. Use enter to exit\n\033[31m");
    do {
        text[counter]=getchar();
        counter++;
    } while (text[counter - 1] != '\n' && counter < 256);
    printf("\033[32m%s\033[0m\n", text);
    return 0;
}
