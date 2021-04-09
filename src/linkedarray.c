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
    int i_arr;
    int num_st=0; // Start i at arr[0]
    LnkArr* curNode = list;

    //Find Node 
    while(curNode->nextNode != NULL){
        
        if ((num_st + curNode->len) > i){
            break;
        }

        else{
            num_st += curNode->len;
            curNode = curNode->nextNode;
        }
    }

     
    curNode->nextNode == NULL;
    //ToDo
}