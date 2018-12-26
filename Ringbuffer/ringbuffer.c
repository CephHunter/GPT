#include "ringbuffer.h"
#include <stdlib.h>

rbuffer_t* rbuffer_create(unsigned int buf_depth) {
    rbuffer_t* buffer = (rbuffer_t*)malloc(sizeof(rbuffer_t));
    buffer->BUFF_DEPTH = buf_depth;
    buffer->wptr = 0;
    buffer->rptr = 0;
    buffer->buffer = (char*)malloc(sizeof(char)*buf_depth);
    return buffer;
}

void rbuffer_free(rbuffer_t* buffer) {
    if (buffer!=0) {
        free(buffer->buffer);
        free(buffer);
    }
}

void rbuffer_push(rbuffer_t* buffer, char data) {
    if (buffer!=0) {
        buffer->buffer[buffer->wptr] = data;
        buffer->wptr++;
        if (buffer->wptr >= buffer->BUFF_DEPTH)
            buffer->wptr = 0;
        if (buffer->wptr == buffer->rptr) {
            (buffer->rptr < (buffer->BUFF_DEPTH-1)) ? buffer->rptr++ : buffer->rptr=0;
        }
    }
}

int rbuffer_pop(rbuffer_t* buffer, char* data) {
//    *data = 0;
//    if (buffer!=0) {
//        if (buffer->ptr > 0) {
//            *data = buffer->buffer[buffer->ptr-1];
//            buffer->ptr--;
//            return 1;
//        }
//    }
    return 0;
}
