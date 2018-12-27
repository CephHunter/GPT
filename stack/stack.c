#include "stack.h"
#include <stdlib.h>

stack_t* stack_create(unsigned int buf_depth) {
    stack_t* buffer = malloc(sizeof *buffer);
    buffer->BUFF_DEPTH = buf_depth;
    buffer->ptr = 0;
    buffer->buffer = malloc(sizeof *(buffer->buffer) * buf_depth);
    return buffer;
}

void stack_free(stack_t** buffer) {
    if (*buffer) {
        free((*buffer)->buffer);
        free(*buffer);
        *buffer = 0;
    }
}

void stack_push(stack_t* buffer, char data) {
    if (buffer) {
        if (buffer->BUFF_DEPTH > buffer->ptr) {
            buffer->buffer[buffer->ptr] = data;
            buffer->ptr++;
        }
    }
}

int stack_pop(stack_t* buffer, char* data) {
    if (buffer && data) {
        *data = 0;
        if (buffer->ptr > 0) {
            *data = buffer->buffer[buffer->ptr-1];
            buffer->ptr--;
            return 1;
        }
    }
    return 0;
}
