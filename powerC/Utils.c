//
// Created by splimter on 04/01/2020.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SortHelper.h"
#include "Utils.h"

static int pint = 0;
static float pfloat = 0.0f;
static char *pstring = "";

const int RUN = 3;

void arr_sort(void **arr, int n, const char *type) {

    if (strcmp(type, Integer) == 0 || strcmp(type, Float) == 0 || strcmp(type, String) == 0) {
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

void arr_inverse(void **arr, int size, const char *type) {
    auto caster;

    if (strcmp(type, Integer) == 0) {
        caster = pint;
    } else if (strcmp(type, Float) == 0) {
        caster = pfloat;
    } else if (strcmp(type, String) == 0) {
        caster = pstring;
    } else {
        printf("error type\n");
        exit(510);
    }

    for (int i = 0; i < size / 2; i++) {
        int t = *((typeof(caster) *) arr + i);
        *((typeof(caster) *) arr + i) = *((typeof(caster) *) arr + size - i - 1);
        *((typeof(caster) *) arr + size - i - 1) = t;
    }

}

int arr_contain(void *array, int size, void *target, const char *type) {
    auto caster;
    if (strcmp(type, Integer) == 0) {
        caster = pint;
    } else if (strcmp(type, Float) == 0) {
        caster = pfloat;
    } else if (strcmp(type, String) == 0) {
        caster = pstring;
    } else {
        printf("error type\n");
        exit(510);
    }
    for (int i = 0; i < size; ++i) {
        if (*((typeof(caster) *) (array) + i) == *(typeof(caster) *) target)
            return i;
    }

    return -1;
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
