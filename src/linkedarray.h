/**
 * @file linkedarray.h
 * @author Steven Shao-Ting Chiu (r07945001@ntu.edu.tw)
 * @brief Unrolled linked list for finding K-least element
 * @version 0.1
 * @date 2021-04-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LINKEDARRAY_H
#define LINKEDARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define subN 100

/** * Node with arrays.
 * @param len length of stored data
 * @param isSorted `0` for unsorted array, `1` sorted
 * @param flag direction of reading. `0` means starts from head; `1` end.
 * @param arrInx Data in index order
 * @param arrSort Array for ordered data
 * Ref: 
 * - Design: https://github.com/stevengogogo/DSA-KLeastElement
 */
typedef struct node{
    int len;
    int isSorted;
    int flag;
    int arrInx[subN];
    int arrSort[subN];
    struct node* nextNode;
} LnkArr;

typedef struct {
    LnkArr* node;
    int i;
    int isEnd;
} loc;


/** * Initiate empty linked array */
LnkArr* init_list_empty(void);
void kill_list(LnkArr*);

/** * Insert x at ith position. i starts at 1
 * @return 1 create new node, 0
*/
int insert(LnkArr*, int i, int x);

loc find_ith(LnkArr* list, int i);

#endif
