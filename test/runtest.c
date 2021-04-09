#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_linkedarray.h"


// Run TESTs 
TEST_LIST = {
    {"Utility", test_utils},
    {"LnkArr Initiation", test_init},
    {"find", test_find},
    {NULL, NULL} // Terminate the test
};