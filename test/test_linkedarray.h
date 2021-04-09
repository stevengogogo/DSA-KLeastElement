#ifndef TEST_LINKEDARRAY_H
#define TEST_LINKEDARRAY_H

#include "linkedarray.h"

void test_init(void){
    LnkArr* list = init_list_empty();
    kill_list(list);
}

void test_find(void){
    LnkArr* list = init_list_empty();

    int arr[] = {1,4,2,6,2};
    int arr_sorted[] = {1,2,2,4,6};
    int len = 5;

    for(int i=0;i<len;i++){
        list->arrInx[i] = arr[i];
        list->arrSort[i] = arr_sorted[i];
    }

    list->flag = 1;
    list->len = len;
    list->nextNode = NULL;

    //Find
    Loc loc;
    for(int i=1; i<=len;i++){
        loc = find_ith(list,i);
        TEST_ASSERT((loc.i+1) == i);
        TEST_ASSERT((loc.isEnd) == 0);
    }

    // New site
    loc = find_ith(list, len+1);
    TEST_ASSERT((loc.i) == len);
    TEST_ASSERT(loc.isEnd == 1);
}


#endif