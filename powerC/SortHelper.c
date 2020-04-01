//
// Created by splimter on 24/12/2019.
//
#include <string.h>

static const char *STRING = "string", *INTERGER = "integer", *DOUBLE = "float";

/// TO be used in arr_sort()
void insertionSort(void *arr[], int left, int right, const char *type) {

    if (strcmp(type, INTERGER) == 0) {
        for (int i = left + 1; i <= right; i++) {
            int temp = *((int *) (arr) + i);
            int j = i - 1;
            while (*((int *) (arr) + j) > temp && j >= left) {
                *((int *) (arr) + j + 1) = *((int *) (arr) + j);
                j--;
            }
            *((int *) (arr) + j + 1) = temp;
        }
    } else if (strcmp(type, DOUBLE) == 0) {
        for (int i = left + 1; i <= right; i++) {
            double temp = *((double *) (arr) + i);
            int j = i - 1;
            while (*((double *) (arr) + j) > temp && j >= left) {
                *((double *) (arr) + j + 1) = *((double *) (arr) + j);
                j--;
            }
            *((double *) (arr) + j + 1) = temp;
        }
    } else if (strcmp(type, STRING) == 0) {
        for (int i = left + 1; i <= right; i++) {
            char * temp = *((char **) (arr) + i);
            int j = i - 1;
            while (*((char **) (arr) + j) > temp && j >= left) {
                *((char **) (arr) + j + 1) = *((char **) (arr) + j);
                j--;
            }
            *((char **) (arr) + j + 1) = temp;
        }
    }
}

void mergeSort(void *arr[], int l, int m, int r, const char *type) {
    int len1 = m - l + 1, len2 = r - m;
    void *left[len1], *right[len2];

    if (type == INTERGER) {
        for (int i = 0; i < len1; i++)
            *((int *) (left) + i) = *((int *) (arr) + l + i);
        for (int i = 0; i < len2; i++)
            *((int *) (right) + i) = *((int *) (arr) + m + 1 + i);
    } else if (type == DOUBLE) {
        for (int i = 0; i < len1; i++)
            *((double *) (left) + i) = *((double *) (arr) + l + i);
        for (int i = 0; i < len2; i++)
            *((double *) (right) + i) = *((double *) (arr) + m + 1 + i);
    } else if (type == STRING) {
        for (int i = 0; i < len1; i++)
            *((char **) (left) + i) = *((char **) (arr) + l + i);
        for (int i = 0; i < len2; i++)
            *((char **) (right) + i) = *((char **) (arr) + m + 1 + i);
    }


    int i = 0, j = 0, k = l;

    if (type == INTERGER) {
        while (i < len1 && j < len2) {
            if (*((int *) (left) + i) <= *((int *) (right) + j)) {
                *((int *) (arr) + k) = *((int *) (left) + i);
                i++;
            } else {
                *((int *) (arr) + k) = *((int *) (right) + j);
                j++;
            }
            k++;
        }
        while (i < len1) {
            *((int *) (arr) + k) = *((int *) (left) + i);
            k++;
            i++;
        }
        while (j < len2) {
            *((int *) (arr) + k) = *((int *) (right) + j);
            k++;
            j++;
        }
    } else if (type == DOUBLE) {
        while (i < len1 && j < len2) {
            if (*((double *) (left) + i) <= *((double *) (right) + j)) {
                *((double *) (arr) + k) = *((double *) (left) + i);
                i++;
            } else {
                *((double *) (arr) + k) = *((double *) (right) + j);
                j++;
            }
            k++;
        }
        while (i < len1) {
            *((double *) (arr) + k) = *((double *) (left) + i);
            k++;
            i++;
        }
        while (j < len2) {
            *((double *) (arr) + k) = *((double *) (right) + j);
            k++;
            j++;
        }
    } else if (type == STRING) {
        while (i < len1 && j < len2) {
            if (*((char **) (left) + i) <= *((char **) (right) + j)) {
                *((char **) (arr) + k) = *((char **) (left) + i);
                i++;
            } else {
                *((char **) (arr) + k) = *((char **) (right) + j);
                j++;
            }
            k++;
        }
        while (i < len1) {
            *((char **) (arr) + k) = *((char **) (left) + i);
            k++;
            i++;
        }
        while (j < len2) {
            *((char **) (arr) + k) = *((char **) (right) + j);
            k++;
            j++;
        }
    }
}

// min function return min between 2
int minSort(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}
