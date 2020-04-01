# Power-C
Most popular and used libraries and algorithms to make C easy as others. 

## libs
### ArrayList.h

@details
* Always init the list using: al_init
* Always destroy the list using: al_destroy
* C operation: al_append, al_prepend
* R operation: al_getAtIndex, al_contain
* U operation: al_setAtIndex, al_sort, al_reverse
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
* arr_contain

@warning
* 510 type error

## Notes
Supported type `int`, `double`, `char`, `char * (string)`, as for `float` is dropped and `struct` will be added in future.


Floating-point decimal values generally do not have an exact binary representation.<br>
This is a side effect of how the CPU represents floating point data.<br>
For this reason, you may experience some loss of precision, 
and some floating-point operations may produce unexpected results.<br>
To resolve the behavior, most programmers either ensure that the value is greater or less than what is needed, 
or they get and use a Binary Coded Decimal (BCD) library that will maintain the precision.<br>
Therefore `DOUBLE_EQ` is made.<br>
