#include <stdio.h>

void read_console(char* buffer, int size) {
    int length = 0;
    printf("Enter text. Use enter to exit\n");
    do {
        buffer[length++] = getchar();
    } while ((buffer[length-1] != '\n') && (length < (size-1)));
    buffer[length] = 0;
}

int main()
{
    char message[4];
    read_console(message, 4);
    printf("%s", message);
    return 0;
}
