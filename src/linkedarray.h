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
#include <assert.h>
#include <string.h>
#include "utils.h"

#define subN 2000

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

/**
 * @brief Position in linked array
 * @param node the array contains the ith member
 * @param i index in node.array[i]
 * @param isEnd is i-1 the end of the sequence? 
 *              - 0 means node.array[i] is the ith position
 *              - 1 means node.array[i] is the (i-1)th position
 */
typedef struct {
    LnkArr* node;
    LnkArr* nodePrev;
    LnkArr* nodeNext;
    int i;
    int isEnd;
    int numCum;
} Loc;


/** * Initiate empty linked array */
LnkArr* init_list_empty(void);
void kill_list(LnkArr*);


/** * Insert x at ith position. i starts at 1
 * @return 1 create new node, 0
*/
int insert(LnkArr*, int i, int x);

void insertLArray(Loc nodeLoc, int x);

/**
 * @brief Split the node to extend. The splited node is wired to the next node
 * 
 * @param nodeLoc 
 * @return Loc Location of first node.
 */
void splitNode(Loc nodeLoc);

/** * Delete */
int delete(LnkArr* list, int i);
/** * Remove an element*/
void remove_LArray(Loc nodeLoc);
/** * Free the node*/
void kill_LArray(Loc nodeLoc);

/** * Reverse */
int reverse(LnkArr* list, int str, int end);

/** * Find the position in linked array */
Loc find_LnkArr_ith(LnkArr* headList, int i);

/** * Find ith begin with a start node and sum of previous length */
Loc find_LnkArr_ith_bounded(LnkArr* startNode, LnkArr* prevNode, int sumLenPrev, int i);

/** * Get ith variable */
int get_ith_var(LnkArr* headList, int i);

int get_i2read(int i, int flag, int length);

void update_orderArr(LnkArr* node);

#endif
