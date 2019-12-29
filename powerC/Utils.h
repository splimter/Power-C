//
// Created by splimter on 21/12/2019.
//

#ifndef POWERC_UTILS_H
#define POWERC_UTILS_H

/// @details
/// utl_sort - sort array
/// utl_reverse - reverse array

/// @warning
/// 510 type error

#include <stdio.h>
#include "SortHelper.h"

const char *String = "string", *Integer = "integer", *Float = "float";
static int pint = 0;
static float pfloat = 0.0f;
static char *pstring = "";

const int RUN = 3;

/// sort array
/// \param arr - array to be sorted
/// \param n - array size
/// \param type - String, Integer, Float
void utl_sort(void *arr[], int n, const char *type) {

    if (type == Integer || type == Float || type == String) {
        for (int i = 0; i < n; i += RUN)
            insertionSort(arr, i, minSort((i + 31), (n - 1)), type);

        for (int size = RUN; size < n; size = 2 * size)
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = minSort((left + 2 * size - 1), (n - 1));
                mergeSort(arr, left, mid, right, Integer);
            }

    } else {
        printf("type error\n");
        exit(510);
    }

}

/// reverse array
/// \param arr - array to be reversed
/// \param n - array size
/// \param type - String, Integer, Float
void utl_reverse(void *arr[], int n, const char *type) {

    auto caster;
    if (type == Integer) {
        caster = pint;
    } else if (type == Float) {
        caster = pfloat;
    } else if (type == String) {
        caster = pstring;
    } else {
        printf("error type\n");
        exit(510);
    }

    for (int i = 0; i < n / 2; i++) {
        int t = *((typeof(caster) *) arr + i);
        *((typeof(caster) *) arr + i) = *((typeof(caster) *) arr + n - i - 1);
        *((typeof(caster) *) arr + n - i - 1) = t;
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
