#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedarray.h"
#include "utils.h"

int main()
{
    LnkArr* list = init_list_empty();
    int varI;
    int numArr = 1; //number of linked arrays
    int MaxInitLen = subN + 1;

    for (int i=1; i<= MaxInitLen; i++){
        numArr += insert(list, i, i);
        varI = get_ith_var(list, i);
    }


    reverse(list,1, MaxInitLen);

    return 0;
}