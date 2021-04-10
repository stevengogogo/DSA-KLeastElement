#ifndef TEST_LINKEDARRAY_H
#define TEST_LINKEDARRAY_H

#include "linkedarray.h"
#include <time.h>

#define MaxInitLen 100000

void test_init(void){
    LnkArr* list = init_list_empty();
    kill_list(list);
}

void test_find(void){
    LnkArr* list = init_list_empty();
    LnkArr* list2 = init_list_empty();
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


void test_insert_LArray(void){
    LnkArr* list = init_list_empty();
    int varI;
    double time_taken;
    clock_t elp;

    elp = clock();
    for (int i=1; i<= MaxInitLen; i++){
        insert(list, i, i);

        varI = get_ith_var(list, i);
        TEST_CHECK(varI == i);
        TEST_MSG("Expected: %d, but got %d", i, varI);
    }
    elp = clock() - elp;

    time_taken = ((double)elp)/CLOCKS_PER_SEC;

    printf("\n %d insertions: %f sec [Maxlength = %d]", MaxInitLen,time_taken, subN);

    kill_list(list);
}

#endif