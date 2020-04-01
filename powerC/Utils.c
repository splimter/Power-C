//
// Created by splimter on 04/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SortHelper.h"
#include "Utils.h"

#define EPSILON 0.0001   // tolerance
#define DOUBLE_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

const int RUN = 3;

void arr_sort(void **arr, int n, const char *type) {

    if (strcmp(type, INTERGER) == 0 || strcmp(type, DOUBLE) == 0 || strcmp(type, STRING) == 0) {
        for (int i = 0; i < n; i += RUN)
            insertionSort(arr, i, minSort((i + 31), (n - 1)), type);

        for (int size = RUN; size < n; size = 2 * size)
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = minSort((left + 2 * size - 1), (n - 1));
                mergeSort(arr, left, mid, right, INTERGER);
            }

    } else {
        printf("type error on arr_sort call\n");
        exit(510);
    }

}

void arr_inverse(void **arr, int size, const char *type) {
    if (strcmp(type, INTERGER) == 0) {
        for (int i = 0; i < size / 2; i++) {
            int t = *((int*) (arr) + i);
            *((int*) (arr) + i) = *((int*)(arr) + size - i - 1);
            *((int*) (arr) + size - i - 1)= t;
        }
        return;
    } else if (strcmp(type, DOUBLE) == 0) {
        for (int i = 0; i < size / 2; i++) {
            double t = *((double *) (arr) + i);
            *((double*) (arr) + i) = *((double*)(arr) + size - i - 1);
            *((double*) (arr) + size - i - 1)= t;
        }
        return;
    } else if (strcmp(type, STRING) == 0) {
        for (int i = 0; i < size / 2; i++) {
            char *t = *((char **) (arr) + i);
            *((char **) (arr) + i) = *((char **)(arr) + size - i - 1);
            *((char **) (arr) + size - i - 1)= t;
        }
        return;
    } else {
        printf("type error on arr_inverse call\n");
        exit(510);
    }
}

int arr_contains(void **array, int size, void *target, const char *type) {
    if (strcmp(type, INTERGER) == 0) {
        for (int i = 0; i < size; ++i) {
            if (*((int *) (array) + i) == *(int *) target)
                return i;
        }
    } else if (strcmp(type, DOUBLE) == 0) {
        for (int i = 0; i < size; ++i) {
            if (DOUBLE_EQ(*((double *) (array) + i),*(double *) target))
                return i;
        }
    } else if (strcmp(type, STRING) == 0) {
        for (int i = 0; i < size; ++i) {
            if ( *((char **) array + i) == *(char **) target)
                return i;
        }
    } else {
        printf("type error on arr_contains call\n");
        exit(510);
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
