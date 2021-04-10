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
    {"LnkArr Initiation", test_init},    
    {"find", test_find},
    {NULL, NULL} // Terminate the test
};