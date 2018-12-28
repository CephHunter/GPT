#include "ringbuffer.h"
#include <stdlib.h>

queue_t* rbuffer_create() {
    queue_t* buffer = malloc(sizeof *buffer);
    buffer->first = 0;
    buffer->last = 0;
    return buffer;
}

void rbuffer_free(queue_t** buffer) {
    if (*buffer) {
        list_t* current = (*buffer)->last;
        list_t* previous;
        while (current) {
            previous = current->previous;
            free(current);
            current = previous;
        }
        free(*buffer);
        *buffer = 0;
    }
}

void rbuffer_write(queue_t* buffer, char data) {
    if (buffer) {
        list_t* next = malloc(sizeof *next);
        if (next) {
            next->next = 0;
            next->previous = buffer->last;
            next->data = data;
            if (buffer->last)
                buffer->last->next = next;
            buffer->last = next;

            if (buffer->first == 0)
                buffer->first = next;
        }
    }
}

int rbuffer_read(queue_t* buffer, char* data) {
    if (buffer && data) {
        *data = 0;
        list_t* current = buffer->first;
        if (current) {
            *data = current->data;
            if (current->next)
                current->next->previous = 0;
            buffer->first = current->next;
            if (current == buffer->last)
                buffer->last = 0;
            free(current);
            return 1;
        }
    }
    return 0;
}















