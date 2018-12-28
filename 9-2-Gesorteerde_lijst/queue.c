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

void queue_enqueue(queue_t** buffer, char data) {
    if (buffer && *buffer) {
        queue_t* newElement = malloc(sizeof *newElement);
        if (newElement) {
            queue_t* prev = *buffer;
            queue_t* current = *buffer;
            while (current->next && current->data < data) {
                prev = current;
                current = current->next;
            }

            if (current->next == 0) {
                newElement->next = 0;
                current->next = newElement;
                current->data = data;
            }
            else if (current == *buffer) {
                newElement->data = data;
                newElement->next = *buffer;
                *buffer = newElement;
            }
            else {
                newElement->data = data;
                newElement->next = current;
                prev->next = newElement;
            }
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















