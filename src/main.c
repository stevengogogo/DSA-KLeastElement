#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedarray.h"
#include "utils.h"


LnkArr* createlistRandom(int Len);

int main()
{
   
    LnkArr* list = createlistRandom(3*subN);

    Loc nodeStr = find_LnkArr_ith(list, 1);
    Loc nodeEnd = find_LnkArr_ith(list, 3*subN);

    flipFullNodes(nodeStr, nodeEnd);

    kill_list(list);

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