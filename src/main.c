#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedarray.h"
#include "utils.h"


LnkArr* createlistRandom(int Len);

int main()
{
   
    int Len = 2*subN;
    LnkArr* list = createlistRandom(Len);

    int L,R;
    for (int i=0;i<1000;i++){
        L = rand() % Len + 1 ;

        if (L!= Len)
            R = L + rand() % (Len-L);
        else
          R=L;
        
        printf("L:%d ; R:%d\n", L, R);
        reverse(&list, L, R);
        get_ith_var(list, Len);
    }

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