#include "linkedarray.h"



LnkArr* init_list_empty(void){
    LnkArr* list = (LnkArr*)malloc( sizeof(LnkArr) );
    list->flag = 0;
    list->isSorted = 0;
    list->len = 0;
    list->nextNode = NULL;
    return list;
}

void kill_list(LnkArr* list){
    LnkArr* nxt;
    LnkArr* cur=list;
    
    while (cur != NULL){
        nxt = cur->nextNode;
        free(cur);
        cur = nxt;
    }
}

int insert(LnkArr* list, int i, int x){

    Loc iloc = find_LnkArr_ith(list, i);

    if (iloc.node->len < subN){ // Sufficient space for insertion
        insert_array(iloc, x);
    }

    // ToDo: insufficient space / sorting
}

void insert_array(Loc iloc, int x){
    int flag = iloc.node->flag;
    int* arr = iloc.node->arrInx;
    //ToDo
}

Loc find_LnkArr_ith(LnkArr* headList, int i){
    return find_LnkArr_ith_bounded(headList, NULL, 0, i);
}

Loc find_LnkArr_ith_bounded(LnkArr* startNode, LnkArr* prevNode, int sumLenPrev, int i){
    
    int num_st = sumLenPrev; 
    Loc posI;
    // Location Info
    int i_arr; 
    int isEnd;
    LnkArr* node = startNode;

    posI.nodePrev = prevNode; // No previous array at start

    if (i==1){ // First array  
        assert(prevNode == NULL);
        posI.node = node;
        posI.nodeNext = node->nextNode;
        posI.i = 0;
        posI.isEnd = 0; // there is no i-1 for i=1
        return posI;
    }

    while (1){
        if ((num_st + node->len) >= i){ // find ith location
            i_arr = i - num_st - 1;
            isEnd = 0;
            break;
        }
        else{
            if (node->nextNode == NULL){ // end of list
                i_arr = node->len - 1; // last element. 
                assert( (node->len + num_st) == (i - 1)); // i is at end
                isEnd = 1; // (i-1) th element
                break;
            }
            num_st += node->len;

            // Move to next node
            posI.nodePrev = node;
            node = node->nextNode;
        }
    }

    posI.node=node;
    posI.nodeNext = node->nextNode;
    posI.i = i_arr;
    posI.isEnd = isEnd;

    return posI;
}