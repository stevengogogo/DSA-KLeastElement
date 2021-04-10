#ifndef TEST_LINKEDARRAY_H
#define TEST_LINKEDARRAY_H

#include "linkedarray.h"

void test_init(void){
    LnkArr* list = init_list_empty();
    kill_list(list);
}

void test_find(void){
    LnkArr* list = init_list_empty();
    LnkArr* list2;
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

    memcpy(list2, list, sizeof(LnkArr)); // create second array
    list->nextNode = list2;

    //Find
    Loc loc;
    for(int i=1; i<=len;i++){
        loc = find_LnkArr_ith(list,i);
        TEST_CHECK((loc.i+1) == i);
        TEST_CHECK((loc.isEnd) == 0);
    }

    // New site
    loc = find_LnkArr_ith(list, 2*len + 1);
    TEST_CHECK((loc.i) == len-1);
    TEST_MSG("loc.i (%d) !=  %d", loc.i, len-1);
    TEST_CHECK(loc.isEnd == 1);
    TEST_CHECK(loc.nodeNext == NULL);
    TEST_CHECK(loc.nodePrev != NULL);
}


#endif