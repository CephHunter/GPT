#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue_t {
    char* buffer;
    unsigned int BUFF_DEPTH;
    unsigned int ptr;
} queue_t;

queue_t* queue_create(unsigned int buf_depth);
void queue_free(queue_t** buffer);
void queue_enqueue(queue_t* buffer, char data);
int queue_dequeue(queue_t* buffer, char* data);

#endif // QUEUE_H
