#include "queue.h"
#include <stdlib.h>

queue_t* queue_create(unsigned int buf_depth) {
    queue_t* buffer = malloc(sizeof(*buffer));
    buffer->BUFF_DEPTH = buf_depth;
    buffer->ptr = 0;
    buffer->buffer = malloc(sizeof *(buffer->buffer) * buf_depth);
    return buffer;
}

void queue_free(queue_t** buffer) {
    if (*buffer) {
        free((*buffer)->buffer);
        free(*buffer);
        *buffer = 0;
    }
}

void queue_enqueue(queue_t* buffer, char data) {
    if (buffer) {
        if (buffer->BUFF_DEPTH > buffer->ptr) {
            buffer->buffer[buffer->ptr] = data;
            buffer->ptr++;
        }
    }
}

int queue_dequeue(queue_t* buffer, char* data) {
    if (buffer && data) {
        *data = 0;
        if (buffer->ptr > 0) {
            *data = buffer->buffer[0];
            for (unsigned int i = 0; i < buffer->BUFF_DEPTH-1; i++) {
                buffer->buffer[i] = buffer->buffer[i+1];
            }
            buffer->ptr--;
            return 1;
        }
    }
    return 0;
}
