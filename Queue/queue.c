#include "queue.h"
#include <stdlib.h>

queue_t* queue_create(unsigned int buf_depth) {
    queue_t* buffer = (queue_t*)malloc(sizeof(queue_t));
    buffer->BUFF_DEPTH = buf_depth;
    buffer->ptr = 0;
    buffer->buffer = (char*)malloc(sizeof(char)*buf_depth);
    return buffer;
}

void queue_free(queue_t* buffer) {
    if (buffer!=0) {
        free(buffer->buffer);
        free(buffer);
    }
}

void queue_push(queue_t* buffer, char data) {
    if (buffer!=0) {
        if (buffer->BUFF_DEPTH > buffer->ptr) {
            buffer->buffer[buffer->ptr] = data;
            buffer->ptr++;
        }
    }
}

int queue_pop(queue_t* buffer, char* data) {
    *data = 0;
    if (buffer!=0 && data!=0) {
        if (buffer->ptr > 0) {
            *data = (char)buffer->buffer[0];
            for (unsigned int i=0; i<buffer->BUFF_DEPTH-1; i++) {
                buffer->buffer[i] = buffer->buffer[i+1];
            }
            buffer->ptr--;
            return 1;
        }
    }
    return 0;
}
