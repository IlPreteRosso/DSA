#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void merge(int *arr, int start, int mid, int end);
void MergeSort(int *arr, int start, int end);
void InsertionSort(int *arr, int L);
void InsertionSort(int *arr, int L);
void disp(int *arr, int size);
void swap(int *i, int *j);

#define SIZE 100000

int main(){
    int arr1[SIZE], arr2[SIZE];
    int counter = 0;
    while(counter < SIZE){
        arr1[counter] = arr2[counter++] = rand();
    }
    int L = SIZE;
    //disp(arr, L);
    clock_t t0, t1, t2;
    t0 = clock();
    MergeSort(arr1, 0, L-1);
    t1 = clock();
    //disp(arr, L);
    InsertionSort(arr2, (int)L);
    t2 = clock();
    //disp(arr, L);
    printf("Time consumed by MargeSort is %dms, InsertionSort is %dms\n", t1 - t0, t2 - t1);
    return 0;
}

void merge(int *arr, int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr, int start, int end) {
    // the unit subarray(where the algorithm start to retrieve) 
    // is [i] where start = end
    // the [i] subarray is guaranteed as sorted
    if (start < end) {
        int mid = start + (end - start) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void InsertionSort(int *arr, int L){
    int i, key, j;
    for (i = 1; i < L; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void disp(int arr[], int L){
    for (int i = 0; i < L; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return;
}

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
    return;
}


