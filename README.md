# cStringSplitter

I've seen many people who struggle writing a string splitter for C.

So I decided to write one. This one.

Flex: I wrote this in 15 minutes.

## Information for beginners

char* can be saved in a string:

```C
string x = char*
```

char** can be saved in a string array:

```C
string[] x = char**
string * x = char**
```

## Usage

### Get a specific element from a string
---
```C
char *elementAtIndex(char *string, char delimiter, int index);
```

char *string: An array of chars or a string with the element which will be extracted.

char delimiter: The symbol which divides the elements.

int index: The index of the element that has to be extracted.

returns: A char * or a string which contains the wanted element.

```C
char *str = "Alexej:Leon:Edwin:Elias:Jannik:Bent:Frank:Mangold:Ape:Iceberg";
char *name = splitAtIndex(str, ':', 4); // str will contain Jannik
```

### Get all elements from a string as an array
---
```C
char **splitString(char *string, char delimiter);
```

char *string: An array of chars or a string with the elements which will be extracted.

char delimiter: The symbol which divides the elements.

returns: a char ** or a string * which contains all elements.

```C
char *str = "Alexej:Leon:Edwin:Elias:Jannik:Bent:Frank:Mangold:Ape:Iceberg";
char **names = splitString(str, ':'); // names will contain an array of all elements
```

### Count how many elements there are
---
```C
int countElements(char *string, char delimiter);
```

char *string: An array of chars or a string with the elements.

char delimiter: The symbol which divides the elements.

returns: The amount of elements found in the string

```C
char *str = "Alexej:Leon:Edwin:Elias:Jannik:Bent:Frank:Mangold:Ape:Iceberg";
int amount = countElements(str, ':'); // amount will contain the amount of elements
```

## Help

### Add the library to your project and your C Build tool

CMake Example:

```CMake
include_directories(split)

add_executable(lineSplitter main.c split/splitString.c split/splitString.h)
```

### Include the library

```C
#include "./split/splitString.h"
```
