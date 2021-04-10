#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedarray.h"
#include "utils.h"

int main()
{
    int MaxInitLen = 10000;
    LnkArr* list = init_list_empty();
    int varI;
    int numArr = 0; //number of linked arrays

    for (int i=1; i<= MaxInitLen; i++){
        numArr += insert(list, i, i);

        varI = get_ith_var(list, i);
     
    }

    for (int i= MaxInitLen; i>=1; i--){
        numArr -= delete(list, i);
    }

    

    kill_list(list);

    return 0;
}