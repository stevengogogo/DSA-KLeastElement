#include "utils.h"


void quicksort(int arr[], int left, int right){
    if (left< right){
        int q = partition(arr, left, right);
        quicksort(arr, left, q-1);
        quicksort(arr, q+1, right);
    }
}

int partition(int arr[], int left, int right){
    int i = left-1;
    int j;
    for(j=left; j < right; j++){
        if(arr[j] <= arr[right]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[right]);

    return i+1;
}

void swap(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int insert_arr(int arr[], int i_, int x, int length){
    assert(length > 0); // Don't allow empty array

    int moveNum = length - 1 - i_;

    // Relocate elements
    for (int j=(length-2); j>= i_; j--)
        arr[j+1] = arr[j];

    arr[i_] = x;

    return moveNum;
}

void append_arr(int arr[], int x, int length){
    insert_arr(arr, length-1, x, length);
}

void remove_arr(int arr[], int i, int length){
    for(int j=i; j<length-1;j++){
        arr[j] = arr[j+1];
    }
}

int reverse_arr(int arr[], int str, int end){
    assert(str>=0);
    assert(end>=0);
    int STR = str;
    int END = end;
    int flip = 0;

    if (STR > END){
        swap(&STR, &END);
        ++flip;
    }
    while (STR < END)
    {
        swap(&arr[STR], &arr[END]);
        STR++;
        END--;
    }  
    return flip;
}

int compare_array(int A[], int B[], int length){
    for (int i=0;i<length;i++){
        if(A[i] != B[i])
            return 0;
    }
    return 1;
}


int BinarySearch_MinBigger(int* arr, int length, int key){
    int low = 0;
    int high = length - 1;
    int mid;
    assert(high>=low);

    int ans = length -1 ;

    while(high >= low){
        mid = (high+low) / 2;
        if (key >= arr[mid]){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int BinarySearch_MaxSmaller(int* arr, int length, int key){
    //TODO
}
