#include <stdio.h>
#include <stdarg.h>

int print_format(char* str, ...) {
    va_list arguments;
    int i = 0, argcount = 0;
    while (str[i] != 0) {
        if (str[i] == '%')
            argcount++;
        i++;
    }
    va_start(arguments, argcount);

    i = 0;
    while (str[i] != 0) {
        if (str[i] ==  '%') {
            char type = str[i+1];
            if (type == 'd')
                printf("\033[32m%d\033[0m", va_arg(arguments, int));
            if (type == 's')
                printf("\033[31m%s\033[0m", va_arg(arguments, char*));
            if (type == 'f')
                printf("\033[33m%f\033[0m", va_arg(arguments, double));
            i++;
        } else {
            printf("%c", str[i]);
        }
        i++;
    }

    va_end(arguments);
    return 1;
}

int main()
{
    print_format("hello %d\nand %s\nworld %f\n", 10, "fffa", 3.215);
    return 0;
}

