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
    int arr = iloc.node->arrInx;
    //ToDo
}

Loc find_LnkArr_ith(LnkArr* list, int i){
    int num_st = 0;
    Loc posI;
    // Location Info
    int i_arr; 
    int isEnd;
    LnkArr* node = list;

    if (i==1){  
        posI.node = node;
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
                i_arr = node->len; // last element. 
                assert( (node->len + num_st) == (i - 1)); // i is at end
                isEnd = 1; // (i-1) th element
                break;
            }
            num_st += node->len;
            node = node->nextNode;
        }
    }

    posI.node=node;
    posI.i = i_arr;
    posI.isEnd = isEnd;

    return posI;
}