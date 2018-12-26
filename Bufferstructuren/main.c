#include <stdio.h>
#include "stack.h"

int main()
{
    char data;
    stack_t* stack1 = stack_create(16);
    stack_push(stack1, 'A');
    stack_push(stack1, 'B');
    stack_push(stack1, 'C');
    stack_push(stack1, 'D');

    while (stack_pop(stack1, &data)) printf("%c\n", data);

    stack_free(stack1);
    return 0;
}
