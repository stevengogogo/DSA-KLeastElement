#include "interfaceDebug.h"

void interfaceDebugging(void){
    LnkArr* list = init_list_empty();
    array listArr = init_array();

    int n, q; //n: #n initial seq; q: #n of commands
    char cmd[30];
    int val;
    int v0,v1,v2;
    scanf("%d", &n);
    scanf("%d", &q);

    //Initial seq
    for(int i=1; i<=n;i++){
        scanf("%d", &val);
        insert_array(&listArr, i, val);
        insert(list, i, val);
    }
    

    // Commands
    for(int i=0;i<q;i++){
        scanf("%s", cmd);
        if (strcmp(cmd, "Delete") == 0){
            scanf("%d", &v0);
            delete_array(&listArr, v0);
            delete(list, v0);
        }
        else if(strcmp(cmd, "Insert") == 0){
            scanf("%d", &v0);// loc
            scanf("%d", &v1);// val
            insert_array(&listArr, v0, v1);
            insert(list, v0, v1);
        }
        else if(strcmp(cmd, "Query") == 0){
            scanf("%d", &v0);// loc
            scanf("%d", &v1);// val
            scanf("%d", &v2);
            query(list, v0, v1, v2);  
            printf("\n");  
        }
        else if(strcmp(cmd, "Reverse") == 0){
            scanf("%d", &v0);// loc
            scanf("%d", &v1);// val
            reverse_array(&listArr, v0, v1);
            reverse(&list, v0, v1);
        }
        else {
            assert(1==0);
        }

        compare_LA_array(&listArr, list);
    }

    kill_list(list);
}


void interfaceDebuggingFile(char* filename){
    FILE *fp;
    fp = fopen(filename, "r");  

    LnkArr* list = init_list_empty();
    array listArr = init_array();

    int n, q; //n: #n initial seq; q: #n of commands
    char cmd[30];
    int val;
    int v0,v1,v2;
    int qu=0;
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &q);

    //Initial seq
    for(int i=1; i<=n;i++){
        fscanf(fp,"%d", &val);
        insert_array(&listArr, i, val);
        insert(list, i, val);
    }
    

    // Commands
    for(int i=1;i<=q;i++){
        fscanf(fp,"%s", cmd);
        if (strcmp(cmd, "Delete") == 0){
            fscanf(fp,"%d", &v0);
            delete_array(&listArr, v0);
            delete(list, v0);
        }
        else if(strcmp(cmd, "Insert") == 0){
            fscanf(fp, "%d", &v0);// loc
            fscanf(fp, "%d", &v1);// val
            insert_array(&listArr, v0, v1);
            insert(list, v0, v1);
        }
        else if(strcmp(cmd, "Query") == 0){
            fscanf(fp, "%d", &v0);// loc
            fscanf(fp, "%d", &v1);// val
            fscanf(fp, "%d", &v2);
            ++qu;
            query(list, v0, v1, v2);  
            printf("\n");  
        }
        else if(strcmp(cmd, "Reverse") == 0){
            fscanf(fp, "%d", &v0);// loc
            fscanf(fp, "%d", &v1);// val
            reverse_array(&listArr, v0, v1);
            reverse(&list, v0, v1);
        }
        else {
            assert(1==0);
        }

        compare_LA_array(&listArr, list);
    }

    kill_list(list);
}

int compare_LA_array(array* arr, LnkArr* list){
    int diff = 0;
    array diffIs = init_array();
    for (int i=0;i<(arr->len);i++){
        if (arr->arr[i] != get_ith_var(list, i+1)){
            printf("Real: %d, List: %d at %d", arr->arr[i], get_ith_var(list, i+1), i+1);
            ++diff;
            
            diffIs.arr[diffIs.len] = i;
            ++diffIs.len;
            
        }
    }
    if (diff>0){
        printf("Difference: %d", diff);
    }
    assert(diff==0);
}

