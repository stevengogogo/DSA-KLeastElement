/**
 * @file main.c
 * @author Steven Shao-Ting Chiu (r07945001@ntu.edu.tw)
 * @brief DSA2021 HW1 P6: K least member. This package is majorly done by myself. The algorithm part is inspired by Zeng Zi-Yan (Thursday TA). The quick sort algorithm is inspired by GreekforGeek, and I have cited the reference in comment. Please see [Project Website](https://stevengogogo.github.io/DSA-KLeastElement/) for the details.
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedarray.h"

LnkArr* createlistRandom(int Len);

int main()
{
    interface();

    //interfaceDebugging();

    return 0;
}


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
