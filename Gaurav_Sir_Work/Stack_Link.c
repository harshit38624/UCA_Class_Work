#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

void initialize(struct stack *st) {
    st->top = NULL;
}

void push(struct stack *st, int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = st->top;
    st->top = newNode;
}

int pop(struct stack *st) {
    if(st->top == NULL) {
        printf("Empty\n");
        return -1;
    }
    int item = st->top->data;
    struct node* temp = st->top;
    st->top = st->top->next;
    free(temp);
    return item;
}

int isEmpty(struct stack *st) {
    return st->top == NULL;
}

void deinitialize(struct stack *st) {
    while(st->top != NULL) {
        struct node *curr = st->top;
        st->top = st->top->next;
        free(curr);
    }
}
int main() {
    struct stack st;
    initialize(&st);

    push(&st, 10);
    push(&st, 20);
    printf("%d",pop(&st));
    deinitialize(&st);
}