#include <stdio.h>
#include "ringbuffer.h"

int main()
{
    char data;
    rbuffer_t* stack1 = rbuffer_create(3);
    rbuffer_push(stack1, 'A');
    rbuffer_push(stack1, 'B');
    rbuffer_push(stack1, 'C');
    rbuffer_push(stack1, 'D');

//    if (rbuffer_pop(stack1, &data)) printf("%c\n", data);
//    if (rbuffer_pop(stack1, &data)) printf("%c\n", data);
//    if (rbuffer_pop(stack1, &data)) printf("%c\n", data);
//    if (rbuffer_pop(stack1, &data)) printf("%c\n", data);

//    while (rbuffer_pop(stack1, &data)) printf("%c\n", data);

    rbuffer_free(stack1);

    return 0;
}
