#include <stdio.h>
#include <stdlib.h>

struct ArrayList {
    int *arr;
    int size;
    int capacity;
};

void initialize(struct ArrayList *list, int capacity) {
    list->capacity = capacity;
    list->size = 0;
    list->arr = (int*)malloc(list->capacity * sizeof(int));
}

void resize(struct ArrayList *list, int capacity) {
    list->arr = (int*)realloc(list->arr,capacity * sizeof(int));
    list->capacity = capacity;
}

void add(struct ArrayList *list, int value) {
    if(list->size == list->capacity) {
        resize(list, list->capacity * 2);
    }
    list->arr[list->size++] = value;
}

void removeLast(struct ArrayList *list) {
    if(list->size == 0) {
        printf("Empty\n");
        return;
    }

    list->size--;

    if(list->size > 0 && list->size <= list->capacity / 4) {
        resize(list, list->capacity / 2);
    }
}

void printList(struct ArrayList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
}

void deinitialize(struct ArrayList *list) {
    free(list->arr);
}

int main() {
    struct ArrayList li;
    initialize(&li,2);
    add(&li,2);
    add(&li,2);
    add(&li,6);
    add(&li,2);
    add(&li,2);
    add(&li,6);
    add(&li,2);
    add(&li,2);
    add(&li,6);
    add(&li,2);
    add(&li,2);
    add(&li,6);
    printf("%d", li.capacity);
}