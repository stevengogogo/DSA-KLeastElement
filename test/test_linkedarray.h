#ifndef TEST_LINKEDARRAY_H
#define TEST_LINKEDARRAY_H

#include "linkedarray.h"

void test_init(void){
    LnkArr* list = init_list_empty();
    kill_list(list);
}


#endif