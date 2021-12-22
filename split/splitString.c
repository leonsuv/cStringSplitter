//
// Created by leonsuv on 11.03.2021.
//

#include "splitString.h"

// Returns the specific element from "string" on position "index"
char *elementAtIndex(char *string, char delimiter, int index) {
    int foundElements = 0, startElementAt = 0, endElementAt = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i + 1] == '\0' && foundElements == index) {
            endElementAt = i + 1;
            break;
        }
        if (string[i] == delimiter) {
            foundElements++;
            if (foundElements == index)
                startElementAt = i + 1;
            if (foundElements - 1 == index) {
                endElementAt = i;
                break;
            }
        }
    }
    char *buffer = malloc(sizeof(char) * (endElementAt - startElementAt + 1));
    for (int i = 0; i < endElementAt - startElementAt + 1; i++) {
        buffer[i] = string[startElementAt + i];
    }
    buffer[endElementAt - startElementAt] = '\0';
    return buffer;
}

// Returns the amount of elements that shall be split
int countElements(char *string, char delimiter) {
    int amount = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == delimiter) amount++;
        if (string[i + 1] == '\0') {
            if (string[i] != delimiter) {
                amount++;
            }
            break;
        }
    }
    return amount;
}

// Returns all elements that shall be split
char **splitString(char *string, char delimiter) {
    int textSplits = countElements(string, delimiter);
    char **stringArray = malloc(sizeof(char *) * textSplits);

    for (int i = 0; i < textSplits; i++) {
        stringArray[i] = elementAtIndex(string, delimiter, i);
    }
    return stringArray;
}
