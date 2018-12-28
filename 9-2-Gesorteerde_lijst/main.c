#include <stdio.h>
#include "queue.h"

int main()
{
    char data;
    queue_t* queue1 = queue_create();
    queue_enqueue(&queue1, 'A');
    queue_enqueue(&queue1, 'F');
    queue_enqueue(&queue1, 'C');
    queue_enqueue(&queue1, 'B');
    queue_enqueue(&queue1, 'D');
    queue_enqueue(&queue1, 'g');


    while (queue_dequeue(&queue1, &data))
        printf("%c\n", data);

    queue_free(&queue1);
    return 0;
}
