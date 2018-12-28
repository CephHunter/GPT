#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_t {
    char data;
    struct queue_t* next;
} queue_t;

queue_t* queue_create();
void queue_free(queue_t** buffer);
void queue_enqueue(queue_t** buffer, char data);
int queue_dequeue(queue_t** buffer, char* data);

#endif // QUEUE_H
