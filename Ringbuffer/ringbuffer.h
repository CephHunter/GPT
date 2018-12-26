#ifndef RINGBUFFER_H
#define RINGBUFFER_H

typedef struct rbuffer_t {
    unsigned int BUFF_DEPTH;
    unsigned int wptr;
    unsigned int rptr;
    char* buffer;
} rbuffer_t;

rbuffer_t* rbuffer_create(unsigned int buf_depth);
void rbuffer_free(rbuffer_t* buffer);
void rbuffer_push(rbuffer_t* buffer, char data);
int rbuffer_pop(rbuffer_t* buffer, char* data);

#endif // RINGBUFFER_H
