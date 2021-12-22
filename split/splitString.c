//
// Created by leonsuv on 11.03.2021.
//

#include "splitString.h"

// Returns the specific element from "string" on position "iteration"
char *splitAtIndex(char *string, char splitBy, int iteration) {
    int foundSplits = 0, startSplitAt = 0, endSplitAt = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i + 1] == '\0' && foundSplits == iteration) {
            endSplitAt = i + 1;
            break;
        }
        if (string[i] == splitBy) {
            foundSplits++;
            if (foundSplits == iteration)
                startSplitAt = i + 1;
            if (foundSplits - 1 == iteration) {
                endSplitAt = i;
                break;
            }
        }
    }
    char *buffer = malloc(sizeof(char) * (endSplitAt - startSplitAt + 1));
    for (int i = 0; i < endSplitAt - startSplitAt + 1; i++) {
        buffer[i] = string[startSplitAt + i];
    }
    buffer[endSplitAt - startSplitAt] = '\0';
    return buffer;
}

// Returns the amount of elements that shall be split
int countElements(char *string, char splitBy) {
    int amount = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == splitBy) amount++;
        if (string[i + 1] == '\0') {
            if (string[i] != splitBy) {
                amount++;
            }
            break;
        }
    }
    return amount;
}

// Returns all elements that shall be split
char **splitString(char *string, char splitBy) {
    int textSplits = countElements(string, splitBy);
    char **stringArray = malloc(sizeof(char *) * textSplits);

    for (int i = 0; i < textSplits; i++) {
        stringArray[i] = splitAtIndex(string, splitBy, i);
    }
    return stringArray;
}