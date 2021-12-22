//
// Created by leons on 11.03.2021.
//

#ifndef LINESPLITTER_SPLITSTRING_H
#define LINESPLITTER_SPLITSTRING_H

#include <string.h>
#include <malloc.h>

char *splitAtIndex(char *string, char delimiter, int index);
char **splitString(char *string, char delimiter);
int countElements(char *string, char delimiter);

#endif //LINESPLITTER_SPLITSTRING_H
