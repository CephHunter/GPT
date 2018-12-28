#include <stdio.h>
#include "ringbuffer.h"

int main()
{
    char data;
    queue_t* buffer = rbuffer_create();
    rbuffer_write(buffer, 'A');
    rbuffer_write(buffer, 'B');
    rbuffer_write(buffer, 'C');
    rbuffer_write(buffer, 'D');

    while (rbuffer_read(buffer, &data))
        printf("%c\n", data);

    rbuffer_free(&buffer);
    return 0;
}
