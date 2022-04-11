#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
// Remark: Variables cannot be declared 
// **inside** function call expressions

int main(void) {
Queue queue;
double value;
CreateQueue(&queue, 5);
puts("Enqueue 5 items.");
for(int x = 0; x < 5; x++){
    Enqueue(&queue, x);
}
puts("Now attempting to enqueue again...");
Enqueue(&queue, 5.0);
DisplayQueue(&queue);
Dequeue(&queue, &value);
printf("Retrieved element = %f\n", value);
DisplayQueue(&queue);
Enqueue(&queue, 7.0);
DisplayQueue(&queue);
DestroyQueue(&queue);
return 0;
}


void DestroyQueue(Queue *queue){
    free(queue);
    printf("Queue destroyed");
    return;
}

void DisplayQueue(Queue *queue){
    if (IsEmpty(queue)){
        printf("Error: empty queue.\n");
        return;
    }
    int front = queue->front;
    for (int i = queue->counter; i > 0; i--){
        double toPrint = queue->values[front];
        printf("%g\n", toPrint);
        front = (front + 1) % queue->maxSize;
    }
    return;
}

bool Enqueue(Queue *queue, double x){
    if (IsFull(queue)){
        printf("Error: the queue is full.\n");
        return false;
    }
    // rear = front at the first initialization
    queue->rear = (queue->rear + 1) % queue->maxSize;
    queue->values[queue->rear] = x;
    queue->counter ++;
    return true;
}
bool Dequeue(Queue *queue, double *x){
    if (IsEmpty(queue)){
        printf("Error: the queue is empty.\n");
        return false;
    }
    // anyway, empty queue means front is one position 
    // ahead of rear (cyclic)
    queue->front = (queue->front + 1) % queue->maxSize;
    queue->counter --;
    if (queue->counter == 0){
        printf("Empty queue, there is no front value.\n");
    }
    else{
        *x = queue->values[queue->front];
    }
    
    return true;
}

bool IsFull(Queue *queue){
    if (queue->counter == queue->maxSize){
        return true;
    }
    return false;
}

bool IsEmpty(Queue *queue){
    if (queue->counter == 0){
        return true;
    }

    return false;
}

// Creat empty queue with size size
bool CreateQueue(Queue *queue, int size){
    if (size < 1){
        printf("Error: size should be positive.\n");
        return false;
    }
    
    queue->front = 0;
    queue->counter = 0;
    queue->maxSize = size;
    queue->rear = size - 1;
    queue->values = (double*)malloc(size * sizeof(double));

    return true;
}

