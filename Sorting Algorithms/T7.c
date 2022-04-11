#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);
void disp(int arr[], int L);
void swap(int *i, int *j);


#define SIZE 100000

int main(){
    int *arr1 = (int*)malloc(sizeof(int)*SIZE);
    int counter = 0;
    while(counter < SIZE){
        arr1[counter] = rand();
        counter ++;
    }
    int L = SIZE;
    //disp(arr, L);
    clock_t t0, t1;
    t0 = clock();
    QuickSort(arr1, 0, L-1);
    t1 = clock();
    printf("Time consumed by QuickSort is %dms\n", t1 - t0);
    return 0;
}

int partition(int *arr, int low, int high){
    // for fun
    srand((arr[low]+arr[high])/2);
    int piv_i = rand()%(high+1-low)+low;    // ranging from low to high
    int piv = arr[piv_i];
    // partition always end at high
    swap(&arr[piv_i], &arr[high]);

    // dust bin for elements smaller than piv
    int i = low;
    // j < high(excluding high) for skipping pivot
    for (int j = low; j < high; j++){
        // if element smaller than pivot is found
        // swap it with the equal or greater element pointed by i
        if (arr[j] < piv){
            swap(&arr[i], &arr[j]);
            i ++;
        }
    }

    // letting all the elements smaller than piv be at the left subarray
    // elements equal to or larger than piv be at the right subarray
    // i currently points to the first element that bigger than piv
    // so swap arr[i](eql/grt cmped to piv) with arr[high](pivot)
    // thus arr[i](before interchange) stays in the right subarray during shifting
    // and we can make a partition about arr[i] after shifting
    swap(&arr[i], &arr[high]);

    //now the pivot is on index i
    return i;
}

void QuickSort(int *arr, int low, int high){
    if (low >= high){
        return;
    }

    int piv_i = partition(arr, low, high);
    QuickSort(arr, low, piv_i-1);
    QuickSort(arr, piv_i+1, high);
}

void disp(int *arr, int L){
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
