#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedarray.h"
#include "utils.h"
int main()
{

    LnkArr* list = init_list_empty();

    for (int i=1; i<= subN; i++){
        insert(list, i, i);
    }

    insert(list, subN+1, subN+1);

    kill_list(list);

    return 0;
}