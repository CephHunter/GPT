#include <stdio.h>
#include "queue.h"

int main()
{
    char data;
    queue_t* queue1 = queue_create(4);
    queue_push(queue1, 'A');
    queue_push(queue1, 'B');
    queue_push(queue1, 'C');
    queue_push(queue1, 'D');

//    if (queue_pop(queue1, &data)) printf("%c\n", data);
//    if (queue_pop(queue1, &data)) printf("%c\n", data);
//    if (queue_pop(queue1, &data)) printf("%c\n", data);
    while (queue_pop(queue1, &data)) printf("%c\n", data);

    queue_free(queue1);
    return 0;
}
