//
// Created by leons on 11.03.2021.
//

#ifndef LINESPLITTER_SPLITSTRING_H
#define LINESPLITTER_SPLITSTRING_H

#include <string.h>
#include <malloc.h>

char **splitString(char *string, char splitBy);
char *splitAtIndex(char *string, char splitBy, int iteration);

#endif //LINESPLITTER_SPLITSTRING_H
