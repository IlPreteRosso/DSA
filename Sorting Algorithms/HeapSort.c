#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MAXSIZE 5

typedef struct maxHeap_s {
    int *arr;
    int size;
    int maxSize;
} maxHeap_t;

void QuickSort(int *A, int left, int right);
void HeapSort(int *A, int n);
void insert(maxHeap_t *maxHeap, int v);
void extractMax(maxHeap_t *maxHeap, int *max);
void maxHeapify(maxHeap_t *maxHeap, int i);
bool isFull(maxHeap_t *maxHeap);
bool isEmpty(maxHeap_t *maxHeap);
void swap(int *i, int *j);
void dispArr(maxHeap_t *maxHeap);



int main(void){
    int A[MAXSIZE];
    
    srand(666);
    
    for (int i = 0; i < MAXSIZE; i++){
        A[i] = rand() % 100;
    }
    

    HeapSort(A, MAXSIZE);

    return 0;
}

void HeapSort(int *A, int n){
    maxHeap_t maxHeap;
    // initialize maxHeap
    maxHeap.size = 0;
    maxHeap.maxSize = n;
    maxHeap.arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        insert(&maxHeap, A[i]);
    }

    int max;
    for (int i = 0; i < n; i++){
        extractMax(&maxHeap, &max);
        maxHeap.arr[maxHeap.size] = max;
    }

    // print based on maxSize
    dispArr(&maxHeap);
    return;
}

// bubble up
void insert(maxHeap_t *maxHeap, int v){
    if (isFull(maxHeap)){
        puts("Stop! Heap maxed-out\n");
        return;
    }

    maxHeap->arr[maxHeap->size] = v;
    int hole = maxHeap->size;
    maxHeap->size ++;
    while (hole > 0 && v > maxHeap->arr[(hole - 1) / 2]){
        swap(&(maxHeap->arr[hole]), &(maxHeap->arr[(hole - 1) / 2]));
        hole = (hole - 1) / 2;
    }
    return;
}

void extractMax(maxHeap_t *maxHeap, int *max){
    if (isEmpty(maxHeap)){
        puts("Stop! Empty heap\n");
        return;
    }
    *max = maxHeap->arr[0];
    swap(&maxHeap->arr[0], &maxHeap->arr[maxHeap->size - 1]);
    maxHeap->size --;
    // remenber to store all data in the original arr
    maxHeapify(maxHeap, 0);
    return;
}

// bubble down
void maxHeapify(maxHeap_t *maxHeap, int i){
    int to_swap = i, left_child = 2 * i + 1, right_child = 2 * (i + 1);
    if (left_child < maxHeap->size){
        if (right_child < maxHeap->size){
            if (maxHeap->arr[left_child] < maxHeap->arr[right_child]){
                to_swap = right_child;
            }
            else if (maxHeap->arr[i] < maxHeap->arr[left_child]){
                to_swap = left_child;
            }
        }
        else if(maxHeap->arr[left_child] > maxHeap->arr[i]){
            to_swap = left_child;
        }
    }

    if (to_swap != i){
        swap(&maxHeap->arr[i], &maxHeap->arr[to_swap]);
        maxHeapify(maxHeap, to_swap);
    }
    
    return;
}

bool isFull(maxHeap_t *maxHeap){
    return maxHeap->size == maxHeap->maxSize;
}

bool isEmpty(maxHeap_t *maxHeap){
    return maxHeap->size == 0;
}

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
    return;
}

void dispArr(maxHeap_t *maxHeap){
    for (int i = 0; i < maxHeap->maxSize; i++){
        printf("%d ", maxHeap->arr[i]);
    }
    printf("\n");
    return;
}