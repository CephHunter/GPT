#include <stdio.h>
#include "ringbuffer.h"

int main()
{
    char data;
    rbuffer_t* stack1 = rbuffer_create(3);
    rbuffer_write(stack1, 'A');
    rbuffer_write(stack1, 'B');
    rbuffer_write(stack1, 'C');
    rbuffer_write(stack1, 'D');

    while (rbuffer_read(stack1, &data))
        printf("%c\n", data);

    rbuffer_free(&stack1);

    return 0;
}
