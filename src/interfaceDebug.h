#ifndef INTERFACEDEBUG_H
#define INTERFACEDEBUG_H

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "utils.h"
#include "linkedarray.h"

void interfaceDebugging(void);
void interfaceDebuggingFile(char* filename);
int compare_LA_array(array* arr, LnkArr* list);


#endif