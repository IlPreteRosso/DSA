#include <stdbool.h>


/*
typedef struct{
    double *values;
    int maxSize;
    int front;
    int rear;
    int placeholder;    //????????????? WHY
    int counter;
} Queue;
*/


typedef struct 
{
    double *values;
    int maxSize;
    int front;
    int rear;
    int counter;
} Queue;


// Creates an empty queue whose capacity is size
bool CreateQueue(Queue *queue, int size);

// Returns true if the queue is empty and false otherwise
bool IsEmpty(Queue *queue);

// Returns true if the queue is full and false otherwise
bool IsFull(Queue *queue);

// Adds a new element with value x to the rear of the queue
// Returns true if the operation is successful and false otherwise
bool Enqueue(Queue *queue, double x);

// Removes an element from the front of the queue
// Returns true if the operation is successful and false otherwise
// Passes the value of the front element to x
bool Dequeue(Queue *queue, double *x);

//Prints all the elements of the queue
void DisplayQueue(Queue *queue);

// Frees the memory occupied by the queue
void DestroyQueue(Queue *queue);