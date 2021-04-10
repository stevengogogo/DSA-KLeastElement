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

void test_swap(void){
    int a = 3;
    int b = 2;
    swap(&a, &b);
    TEST_CHECK(a==2);
    TEST_CHECK(b==3);
}

void test_array_insert(void){
    int a[] = {1,2,3,4,5,56,2};
    int aIn[] = {30, 1,2,3,4,5,56};
    int aLen = 7;
    int b[] = {1,-1,-1,-1,-1};
    int bIn[] = {1,2,3,4,5};
    int bIn2[] = {1,2,3,4,5,20};
    int bmaxL = 5;
    int bLen = 1;
    
    // Insert A
    insert_arr(a, 0, 30, aLen);
    TEST_CHECK( compare_array(a, aIn, aLen)==1 );

    // Insert B
    for (int i=bLen; i<bmaxL;i++)
        insert_arr(b, i, i+1, ++bLen);

    TEST_CHECK( compare_array(b, bIn, bLen)==1 );
    TEST_CHECK( bLen == bmaxL);

    // Append
    append_arr(b, 20, ++bLen);
    TEST_CHECK(b[bLen-1] == 20);
    TEST_CHECK( compare_array(b, bIn2, bLen) == 1);
}

void test_binary_search(void){
    int arr[]={-12,0,1,1,2,3,4,5,6,7,8,11,11};
    int aLen = 13;

    TEST_CHECK(BinarySearch_MinBigger(arr, aLen, -13) == 0);
    TEST_CHECK(BinarySearch_MinBigger(arr, aLen, -12) == 1);

    TEST_CHECK(BinarySearch_MinBigger(arr, aLen, 11) == (aLen-1));

    TEST_MSG("Expected: %d, Got %d",(aLen-1),BinarySearch_MinBigger(arr, aLen, (aLen-1)));

    TEST_CHECK(BinarySearch_MinBigger(arr, aLen, 100) == (aLen-1));
    TEST_MSG("Expected: %d, Got %d",(aLen-1),BinarySearch_MinBigger(arr, aLen, (aLen-1)));
    
    // arr[4] == 2 is the first element bigger than 1;
    TEST_CHECK(BinarySearch_MinBigger(arr, aLen, 1) == 4);
    TEST_MSG("Got %d",BinarySearch_MinBigger(arr, aLen, 1));

    // arr[9] == 8 is the first element bigger than 6
    TEST_CHECK(BinarySearch_MinBigger(arr, aLen, 6) == 9); 
    TEST_MSG("Got %d",BinarySearch_MinBigger(arr, aLen, 6));
}


void test_binary_search2(void){
    int arr[]={-12,0,1,1,2,3,4,5,6,7,8,11,11};
    int aLen = 13;
    int Max = 100;
    int Min = -100;
    int i_; // result of Binary search

    for(int key=Min; key<Max; key++){
        i_ = BinarySearch_MinBigger(arr, aLen, key);

        if (i_==0){
            TEST_CHECK(arr[i_] >= key);
            TEST_MSG("Value at %d = %d (key=%d)", i_, arr[i_], key);
        }
        else if (i_ == aLen-1) {
            TEST_CHECK( arr[i_] <= key );
            TEST_MSG("Value at %d = %d (key=%d)", i_, arr[i_], key);
        }
        else {
            TEST_CHECK( arr[i_] > key );
            TEST_CHECK( arr[i_-1] <= key);
            TEST_MSG("Value at (%d,%d) = (%d, %d) (key=%d)", i_ -1, i_, arr[i_ - 1],arr[i_], key);
        }
    }
}

#endif