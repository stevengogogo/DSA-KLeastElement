#ifndef TEST_LINKEDARRAY_H
#define TEST_LINKEDARRAY_H

#include "linkedarray.h"
#include <time.h>
#include <stdlib.h> // rand()

#define MaxInitLen 10000

//HELPER FUNCTION
LnkArr* createlistRandom(int Len){
    LnkArr* list = init_list_empty();
    int I,x;
    for(int i=1; i<= Len; i++){
        I = (rand() % i + 1);
        x = (rand() % (100000*2) - 100000);
        insert(list, I, x);
    }

    return list;
}

//TEST
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
    int numArr = 0;
    clock_t elp;

    elp = clock();
    for (int i=1; i<= MaxInitLen; i++){
        numArr += insert(list, 1, i);

        varI = get_ith_var(list, 1);
        TEST_CHECK(varI == i);
        TEST_MSG("Expected: %d, but got %d", i, varI);
    }
    elp = clock() - elp;

    time_taken = ((double)elp)/CLOCKS_PER_SEC;

    printf("\n %d insertions: %f sec [NumArr=%d/MaxLen = %d]", MaxInitLen,time_taken, numArr,subN);

    kill_list(list);
}

void test_insertRandom(void){
    LnkArr* list = init_list_empty();
    int Len = MaxInitLen;
    int I,x, varI;
    int numArr=0;
    double time_taken;
    clock_t elp;
    elp = clock();
    for(int i=1; i<= Len; i++){
        I = (rand() % i + 1);
        x = (rand() % (100000*2) - 100000);
        numArr += insert(list, I, x);
        varI = get_ith_var(list, I);
        TEST_CHECK(varI == x);
        TEST_MSG("Expected: %d, but got %d", i, varI);
    }
    elp = clock() - elp;

    time_taken = ((double)elp)/CLOCKS_PER_SEC;

    printf("\n %d insertions: %f sec [NumArr=%d/MaxLen = %d]", MaxInitLen,time_taken, numArr,subN);

    kill_list(list);
}


void test_delete(void){
    LnkArr* list = init_list_empty();
    int varI;
    int numArr = 1; //number of linked arrays

    for (int i=1; i<= MaxInitLen; i++){
        numArr += insert(list, i, i);
        varI = get_ith_var(list, i);
    }

    for (int i= MaxInitLen; i>=1; i--){
        numArr -= delete(list, i);
    }

    TEST_CHECK( list->len == 0);
    TEST_MSG("got %d", list->len);
    TEST_CHECK(numArr == 1);
    TEST_MSG("got %d", numArr);

    kill_list(list);
}

void test_reverseLA(void){
    LnkArr* list = init_list_empty();
    int varI;
    int numArr = 1; //number of linked arrays

    for (int i=1; i<= MaxInitLen; i++){
        numArr += insert(list, i, i);
        varI = get_ith_var(list, i);
    }

    //reverse(list, 1,1);
    reverse(&list,1, MaxInitLen);
    //reverse(list,1, MaxInitLen);
    TEST_CHECK(get_ith_var(list, 1) == MaxInitLen);
    TEST_MSG("got %d", get_ith_var(list, 1));



    kill_list(list);
}

void randomReverse(void){
    int Len = 10*subN;
    LnkArr* list = createlistRandom(Len);

    int L,R;
    for (int i=0;i<1000;i++){
        L = rand() % Len + 1 ;
        R = rand() % (Len-L+1) + L;
        TEST_CHECK(L <= R);
        TEST_CHECK(L>0);
        TEST_CHECK(R>0);
        TEST_CHECK(R<=Len);
        //printf("L:%d ; R:%d\n", L, R);
        reverse(&list, L, R);
    }
}

void test_flipnodes(void){
    int len = 3*subN;
    int Istr, Iend;
    LnkArr* list = createlistRandom(len);

    Loc nodeStr = find_LnkArr_ith(list, 1);
    Loc nodeEnd = find_LnkArr_ith(list, 3*subN);
    flipFullNodes(&list, nodeStr, nodeEnd);


    Loc nodeStr2 = find_LnkArr_ith(list, subN);
    Loc nodeEnd2 = find_LnkArr_ith(list, 3*subN);
    flipFullNodes(&list, nodeStr2, nodeEnd2);

    for (int i=1; i<=len; i++ ){
        Istr = (rand() % len) + 1;
        Iend = (rand() % (len-Istr) + Istr+ 1);
        nodeStr = find_LnkArr_ith(list, Istr);
        nodeEnd = find_LnkArr_ith(list, Iend);
        flipFullNodes(&list, nodeStr, nodeEnd);
    }


    kill_list(list);
}

#endif