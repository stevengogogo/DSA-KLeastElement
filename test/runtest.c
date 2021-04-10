#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_linkedarray.h"


// Run TESTs 
TEST_LIST = {
    {"Utility", test_utils},
    {"Util: Swap", test_swap},
    {"Utils: Array Insrtion", test_array_insert},
    {"Utils: Binary Search", test_binary_search},
    {"Utils: Binary Search Screen", test_binary_search2},
    {"Utils: remove element", test_remove_arr},
    {"LnkArr Initiation", test_init},    
    {"find", test_find},
    {"Insert", test_insert_LArray},
    {"Delete", test_delete},
    {NULL, NULL} // Terminate the test
};