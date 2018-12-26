#include "stack.h"
#include <stdlib.h>

stack_t* stack_create(unsigned int buf_depth) {
    stack_t* buffer = (stack_t*)malloc(sizeof(stack_t));
    buffer->BUFF_DEPTH = buf_depth;
    buffer->ptr = 0;
    buffer->buffer = (char*)malloc(sizeof(char)*buf_depth);
    return buffer;
}

void stack_free(stack_t* buffer) {
    if (buffer!=0) {
        free(buffer->buffer);
        free(buffer);
    }
}

void stack_push(stack_t* buffer, char data) {
    if (buffer!=0) {
        if (buffer->BUFF_DEPTH > buffer->ptr) {
            buffer->buffer[buffer->ptr] = data;
            buffer->ptr++;
        }
    }
}

int stack_pop(stack_t* buffer, char* data) {
    *data = 0;
    if (buffer!=0) {
        if (buffer->ptr > 0) {
            *data = buffer->buffer[buffer->ptr-1];
            buffer->ptr--;
            return 1;
        }
    }
    return 0;
}
