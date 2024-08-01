#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

void initialize(struct queue *q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (int* )malloc(q->size * sizeof(int));
}

void push(struct queue *q, int item) {
    if(q->rear == q->size - 1) {
        printf("Full\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = item;
}

int pop(struct queue *q) {
    if(q->rear < q->front || q->front == -1) {
        printf("Empty\n");
        return;
    }
    int item = q->arr[q->front++];
    if(q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

int size(struct queue *q) {
    if(q->front == -1) {
        return 0;
    }
    return q->rear - q->front + 1;
}

int isEmpty(struct queue *q) {
    return (q->rear < q->front ? 1 : 0) || (q->front == -1 && q->rear == -1);
}
int main() {

}