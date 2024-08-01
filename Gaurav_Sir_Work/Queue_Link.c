#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void initialize(struct queue *q) {
    q->front = q->rear = NULL; 
}

void push(struct queue *q, int item) {
    struct node *curr = (struct node*)malloc(sizeof(struct node));
    curr->data = item;
    curr->next = NULL;
    if(q->rear == NULL) {
        q->front = q->rear = curr;
        return;
    }
    q->rear->next = curr;
    q->rear = curr;
}

int pop(struct queue *q) {
    if(q->front == NULL) {
        printf("Empty\n");
        return -1;
    }
    int item = q->front->data;
    struct node* curr = q->front;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->front = q->rear = NULL;
    }
    free(curr);
    return item;
}

int isEmpty(struct queue *q) {
    return q->front == NULL;
}

int main() {

}