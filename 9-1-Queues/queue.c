#include "queue.h"
#include <stdlib.h>

queue_t* queue_create() {
    queue_t* buffer = malloc(sizeof *buffer);
    buffer->data = 0;
    buffer->next = 0;
    return buffer;
}

void queue_free(queue_t** buffer) {
    if (*buffer) {
        queue_t* current = *buffer;
        queue_t* next;
        while (current) {
            next = current->next;
            free(current);
            current = next;
        }
        *buffer = 0;
    }
}

void queue_enqueue(queue_t* buffer, char data) {
    if (buffer) {
        queue_t* next = malloc(sizeof *next);
        if (next) {
            next->next = 0;
            next->data = 0;
            while (buffer->next) {
                buffer = buffer->next;
            }
            buffer->data = data;
            buffer->next = next;
        }
    }
}

int queue_dequeue(queue_t** buffer, char* data) {
    if (buffer && data) {
        *data = 0;
        queue_t* current = *buffer;
        if (current->next) {
            *data = current->data;
            *buffer = current->next;
            free(current);
            return 1;
        }
    }
    return 0;
}















