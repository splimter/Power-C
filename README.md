# Power-C

Most popular and used libraries and algorithms to make C easy as others.

## Full Example

Array list:

```c
#include <stdio.h>
#include "powerC/Utils.h"
#include "powerC/ArrayList.h"

arraylist my_list;
al_init(&my_list, sizeof(int), NULL);

for (int i = 10; i < 20; i++) {
    al_append(&my_list, &i);
}
for (int i = 9; i > 0; i--) {
    al_prepend(&my_list, &i);
}

int ts = 5, fs = 99;
if (al_contains(&my_list, &ts, INTERGER) != -1) {
    printf("found\n");
}
if (al_contains(&my_list, &fs, INTERGER) == -1) {
    printf("not found\n");
}

printf("%d\t", al_getAtIndex(&my_list, 5, INTERGER));
al_setAtIndex(&my_list, 5, &fs);
printf("%d\n", al_getAtIndex(&my_list, 5, INTERGER));

for (int i = 0; i < al_size(&my_list); i++) {
    printf("%d ", al_getAtIndex(&my_list, i, INTERGER));
}
printf("\n");

al_inverse(&my_list, INTERGER);
al_for_each(&my_list, iterate_int);
printf("\n");

al_sort(&my_list, INTERGER);
al_for_each(&my_list, iterate_int);
printf("\n");

al_delAtIndex(&my_list, 1);
al_delHead(&my_list);
al_delTail(&my_list);

al_for_each(&my_list, iterate_int);
```

Array:

```c
int arrint[] = {11, 22, 33, 44, 55, 66};

arr_inverse(arrint, 6, INTERGER);
for (int i = 0; i < 6; ++i) {
    printf("%d ", arrint[i]);
}
printf("\n");

arr_sort(arrint, 6, INTERGER);
for (int i = 0; i < 6; ++i) {
    printf("%d ", arrint[i]);
}
printf("\n");

int falsetar = 555, truetar = 55;
if (arr_contains(arrint, 6, &falsetar, INTERGER) == -1)
    printf("not found\n");
if (arr_contains(arrint, 6, &truetar, INTERGER) != -1)
    printf("found\n");
```

## libs

### ArrayList.h

@details

* Always init the list using: al_init
* Always destroy the list using: al_destroy
* C operation: al_append, al_prepend
* R operation: al_getAtIndex, al_contains, al_for_each
* U operation: al_setAtIndex, al_sort, al_inverse
* D operation: al_delAtIndex, al_delHead, al_delTail
* get arraylist size: al_size

@warning

* 500 Index cannot be below 0
* 501 Index Out of Range
* 502 Empty Array X tolerated

### Utils.h

@details

* arr_sort
* arr_inverse
* arr_contains

@warning

* 510 type error

## Notes

Supported type `int`, `double`, `char`, `char * (string)`, as for `float` is dropped and `struct` will be added in future.

Floating-point decimal values generally do not have an exact binary representation.</br>
This is a side effect of how the CPU represents floating point data.</br>
For this reason, you may experience some loss of precision,
and some floating-point operations may produce unexpected results.</br>
To resolve the behavior, most programmers either ensure that the value is greater or less than what is needed,
or they get and use a Binary Coded Decimal (BCD) library that will maintain the precision.</br>
Therefore `DOUBLE_EQ` is made.</br>
