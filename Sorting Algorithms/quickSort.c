#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int low, int high);
void quickSort(int *arr, int low, int high);
void disp(int *arr, int L);
void swap(int *i, int *j);

int main(){
    int arr[] = {3, 4, 2, 1, 3, 5};
    int L = sizeof(arr)/sizeof(int);
    disp(arr, L);
    quickSort(arr, 0, L-1);
    disp(arr, L);
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

void quickSort(int *arr, int low, int high){
    if (low >= high){
        return;
    }
    

    int piv_i = partition(arr, low, high);
    quickSort(arr, low, piv_i-1);
    quickSort(arr, piv_i+1, high);
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
