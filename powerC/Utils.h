//
// Created by splimter on 21/12/2019.
//
/// @details
/// arr_sort
/// arr_inverse
/// arr-contain

/// @warning
/// 510 type error


#ifndef POWERC_UTILS_H
#define POWERC_UTILS_H

static const char *STRING = "string", *INTERGER = "integer", *DOUBLE = "double";

/// sort array
/// \param arr - array to be sorted
/// \param n - array size
/// \param type - Integer, Float, String
void arr_sort(void **arr, int n, const char *type);

/// reverse array
/// \param arr - array to be reversed
/// \param size - array size
/// \param type - Integer, Float, String
void arr_inverse(void **arr, int size, const char *type);

/// search an element in array
/// \param array
/// \param size - size of the array
/// \param target - &E
/// \param type - Integer, Float, String
/// \return the index of element if found else -1
int arr_contain(void **array, int size, void *target, const char *type);

// utility function to print the Array
void printArrayInt(int *arr, int n);

void printArrayFloat(float *arr, int n);

void printArrayString(char *arr[], int n);

#endif //POWERC_UTILS_H
