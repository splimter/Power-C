//
// Created by splimter on 24/12/2019.
//

extern const char *String, *Integer, *Float;

static int pint = 0;
static float pfloat = 0.0f;
static char *pstring = "";

/// TO be used in utl_sort()
void insertionSort(void *arr[], int left, int right, const char *type) {

    auto caster;
    if (type == Integer) {
        caster = pint;
    } else if (type == Float) {
        caster = pfloat;
    } else if (type == String) {
        caster = pstring;
    }

    for (int i = left + 1; i <= right; i++) {
        int temp = *((typeof(caster) *) (arr) + i);
        int j = i - 1;
        while (*((typeof(caster) *) (arr) + j) > temp && j >= left) {
            *((typeof(caster) *) (arr) + j + 1) = *((typeof(caster) *) (arr) + j);
            j--;
        }
        *((typeof(caster) *) (arr) + j + 1) = temp;
    }

}

void mergeSort(void *arr[], int l, int m, int r, const char *type) {
    int len1 = m - l + 1, len2 = r - m;
    void *left[len1], *right[len2];

    auto caster;
    if (type == Integer) {
        caster = pint;
    } else if (type == Float) {
        caster = pfloat;
    } else if (type == String) {
        caster = pstring;
    }

    for (int i = 0; i < len1; i++)
        *((typeof(caster) *) (left) + i) = *((typeof(caster) *) (arr) + l + i);
    for (int i = 0; i < len2; i++)
        *((typeof(caster) *) (right) + i) = *((typeof(caster) *) (arr) + m + 1 + i);

    int i = 0, j = 0, k = l;

    if (type == Integer) {}
    else if (type == Float) {}
    else if (type == String) {}

    while (i < len1 && j < len2) {
        if (*((typeof(caster) *) (left) + i) <= *((typeof(caster) *) (right) + j)) {
            *((typeof(caster) *) (arr) + k) = *((typeof(caster) *) (left) + i);
            i++;
        } else {
            *((typeof(caster) *) (arr) + k) = *((typeof(caster) *) (right) + j);
            j++;
        }
        k++;
    }
    while (i < len1) {
        *((typeof(caster) *) (arr) + k) = *((typeof(caster) *) (left) + i);
        k++;
        i++;
    }
    while (j < len2) {
        *((typeof(caster) *) (arr) + k) = *((typeof(caster) *) (right) + j);
        k++;
        j++;
    }

}

// min function return min between 2
int minSort(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}
