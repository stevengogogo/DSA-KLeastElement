#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include "acutest.h"
#include "utils.h"

void test_utils(void)
{
    int arr[] = {1,3,61,-232,23,1,0};
    int arr_sorted[] = {-232,0,1,1,3,23,61};
    int len = 7;

    quicksort(arr, 0, len-1);
    
    
    for(int i=0;i<len;i++){
        TEST_ASSERT(arr[i] == arr_sorted[i] );
    }
}


#endif