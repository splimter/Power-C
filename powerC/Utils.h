//
// Created by splimter on 21/12/2019.
//

#ifndef POWERC_UTILS_H
#define POWERC_UTILS_H

/// @details
/// sort - sort array
/// reverse - reverse array

/// @warning
/// 510 type error

#include <stdio.h>
#include "SortHelper.h"

const char *String = "string", *Integer = "integer", *Float = "float";

const int RUN = 3;

/// sort array
/// \param arr - array to be sorted
/// \param n - array size
/// \param type - String, Integer, Float
void utl_sort(void *arr[], int n, const char *type) {

    for (int i = 0; i < n; i += RUN)
        if (type == Integer || type == Float || type == String)
            insertionSort(arr, i, minSort((i + 31), (n - 1)), type);
        else {
            printf("type error\n");
            exit(510);
        }

    for (int size = RUN; size < n; size = 2 * size)
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = minSort((left + 2 * size - 1), (n - 1));
            mergeSort(arr, left, mid, right, Integer);
        }
}

/// reverse array
/// \param arr - array to be reversed
/// \param n - array size
/// \param type - String, Integer, Float
void utl_reverse(void *arr[], int n, const char *type) {
    if (type == Integer)
        for (int i = 0; i < n / 2; i++) {
            int t = *((int *) arr + i);
            *((int *) arr + i) = *((int *) arr + n - i - 1);
            *((int *) arr + n - i - 1) = t;
        }
    else if (type == Float)
        for (int i = 0; i < n / 2; i++) {
            float t = *((float *) arr + i);
            *((float *) arr + i) = *((float *) arr + n - i - 1);
            *((float *) arr + n - i - 1) = t;
        }
    else if (type == String)
        for (int i = 0; i < n / 2; i++) {
            char *t = (char *) arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = (void **) t;
        }
    else {
        printf("error type\n");
        exit(510);
    }

}

// utility function to print the Array
void printArrayInt(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}

void printArrayFloat(float *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%f  ", arr[i]);
    printf("\n");
}

void printArrayString(char *arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s  ", arr[i]);
    printf("\n");
}

#endif //POWERC_UTILS_H
