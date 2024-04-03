#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct maxheap {
    int arr[max];
    int size;
    int capacity;
} heap;

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap* hp, int i) {
    int l = left(i);
    int r = right(i);
    int greatest = i;

    if (l < hp->size && hp->arr[i] < hp->arr[l]) {
        greatest = l;
    }
    if (r < hp->size && hp->arr[greatest] < hp->arr[r]) {
        greatest = r;
    }
    if (greatest != i) {
        swap(&hp->arr[i], &hp->arr[greatest]);
        heapify(hp, greatest);
    }
}

void deletee(heap* hp) {
    if (hp->size == 1) {
        hp->size--;
        printf("\n%d is deleted.\n", hp->arr[0]);
    } else {
        swap(&hp->arr[0], &hp->arr[hp->size - 1]);
        hp->size--;
        printf("\n%d is deleted.\n", hp->arr[hp->size]);
        heapify(hp, 0);
    }
}

void insert(heap* hp, int num) {
    printf("%d is inserted.\n", num);
    if (hp->size == hp->capacity)
        return;
    hp->size++;
    hp->arr[hp->size - 1] = num;

    for (int i = hp->size - 1; i > 0 && hp->arr[i] > hp->arr[parent(i)];) {
        swap(&hp->arr[i], &hp->arr[parent(i)]);
        i = parent(i);
    }
}

void display(heap* hp) {
    for (int i = 0; i < hp->size; i++) {
        printf("%d ", hp->arr[i]);
    }
    printf("\n");
}

int main() {

    heap* hp = (heap*)malloc(sizeof(heap));
    hp->capacity = max;

    insert(hp, 2);
    insert(hp, 4);
    insert(hp, 0);
    insert(hp, 6);
    insert(hp, 5);
    insert(hp, 1);
    insert(hp, 3);

    printf("\n");
    display(hp);

    deletee(hp);
    display(hp);
    deletee(hp);
    display(hp);
    deletee(hp);
    display(hp);
    deletee(hp);
    display(hp);
    deletee(hp);
    display(hp);

    return 0;
}