#include "ringbuffer.h"
#include <stdlib.h>

rbuffer_t* rbuffer_create(unsigned int buf_depth) {
    rbuffer_t* buffer = malloc(sizeof *buffer);
    buffer->BUFF_DEPTH = buf_depth;
    buffer->wptr = 0;
    buffer->rptr = 0;
    buffer->hasContent = 0;
    buffer->buffer = malloc(sizeof *buffer->buffer * buf_depth);
    return buffer;
}

void rbuffer_free(rbuffer_t** buffer) {
    if (*buffer) {
        free((*buffer)->buffer);
        free(*buffer);
        *buffer = 0;
    }
}

void rbuffer_write(rbuffer_t* buffer, char data) {
    if (buffer) {
        if (buffer->hasContent && buffer->wptr == buffer->rptr) {
            buffer->rptr = (buffer->rptr < buffer->BUFF_DEPTH-1) ? buffer->rptr+1 : 0;
        }
        buffer->buffer[buffer->wptr] = data;
        buffer->hasContent = 1;
        buffer->wptr = (buffer->wptr < buffer->BUFF_DEPTH-1) ? buffer->wptr+1 : 0;
    }
}

int rbuffer_read(rbuffer_t* buffer, char* data) {
    if (buffer && data) {
        *data = 0;
        if (buffer->hasContent) {
            *data = buffer->buffer[buffer->rptr];
            buffer->rptr = (buffer->rptr < buffer->BUFF_DEPTH-1) ? buffer->rptr+1 : 0;
            if (buffer->rptr == buffer->wptr)
                buffer->hasContent = 0;
            return 1;
        }
    }
    return 0;
}
