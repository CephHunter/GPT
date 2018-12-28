#ifndef QUEUE_H
#define QUEUE_H

typedef struct list_t {
    char data;
    struct list_t* next;
    struct list_t* previous;
} list_t;

typedef struct {
    list_t* first;
    list_t* last;
} queue_t;

queue_t* rbuffer_create();
void rbuffer_free(queue_t** buffer);
void rbuffer_write(queue_t* buffer, char data);
int rbuffer_read(queue_t* buffer, char* data);

#endif // QUEUE_H
