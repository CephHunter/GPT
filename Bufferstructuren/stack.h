#ifndef STACK_H
#define STACK_H

typedef struct stack_t {
    unsigned int BUFF_DEPTH;
    unsigned int ptr;
    char* buffer;
} stack_t;

stack_t* stack_create(unsigned int buf_depth);
void stack_free(stack_t* buffer);
void stack_push(stack_t* buffer, char data);
int stack_pop(stack_t* buffer, char* data);

#endif // STACK_H
