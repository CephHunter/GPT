#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

//typedef struct collection_t
//{
//    uint8_t chars[4];
//} collection_t;

typedef union convert_t
{
    uint8_t chars[4];
    int value_int;
} convert_t;

int main()
{
    convert_t char2int;
    convert_t *p = &char2int;
    p->chars[0] = 'A';
    p->chars[1] = 0;
    p->chars[2] = 0;
    p->chars[3] = 0;
    printf("Integer value = %d\n", p->value_int);
    return 0;
}
