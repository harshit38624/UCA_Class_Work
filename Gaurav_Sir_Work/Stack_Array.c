#include <stdio.h>
#include <stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};

void initialize(struct stack *st, int size) {
    st->top = -1;
    st->size = size;
    st->arr = (int* )malloc(st->size * sizeof(int));
}

void push(struct stack *st, int item) {
    if(st->top + 1 >= st->size) {
        printf("Full\n");
        return;
    }
    st->top++;
    st->arr[st->top] = item;
}

int pop(struct stack *st) {
    if(st->top == -1) {
        printf("Empty\n");
        return -1;
    }
    return st->arr[st->top--];
}

int size(struct stack *st) {
    return st->top + 1;
}

int isEmpty(struct stack *st) {
    return st->top == -1 ? 1 : 0;
}

void deinitialize(struct stack *st) {
    free(st->arr);
}
int main() {
    struct stack stk;
    initialize(&stk,5);
    push(&stk,10);
    push(&stk,10);
    push(&stk,10);
    push(&stk,70);
    push(&stk,30);
    printf("%d\n",pop(&stk));
    printf("%d\n",size(&stk));
    printf("%d\n",pop(&stk));
    deinitialize(&stk);
}