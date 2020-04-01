//
// Created by splimter on 04/01/2020.
// origin work pseudomuto
//
#ifndef POWERC_ARRAYLIST_H
#define POWERC_ARRAYLIST_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "ArrayList.h"
#include "Utils.h"

/// Initializes a linked list
void al_init(arraylist *list, int elementSize, freeFunction freeFn) {
    assert(elementSize > 0);
    list->logicalLength = 0;
    list->elementSize = elementSize;
    list->head = list->tail = NULL;
    list->freeFn = freeFn;
}

/// Frees dynamically allocated nodes
void al_destroy(arraylist *list) {
    listNode *current;

    while (list->head != NULL) {
        current = list->head;
        list->head = current->next;

        if (list->freeFn) {
            list->freeFn(current->data);
        }

        free(current->data);
        free(current);
    }
}

///  Adds a node to the head of the list
void al_prepend(arraylist *list, void *element) {
    listNode *node = malloc(sizeof(listNode));
    node->data = malloc(list->elementSize);
    memcpy(node->data, element, list->elementSize);

    node->next = list->head;
    list->head = node;

    // first node?
    if (!list->tail) {
        list->tail = list->head;
    }

    list->logicalLength++;
}

/// Adds a node to the tail of the list
void al_append(arraylist *list, void *element) {
    listNode *node = malloc(sizeof(listNode));
    node->data = malloc(list->elementSize);
    node->next = NULL;

    memcpy(node->data, element, list->elementSize);

    if (list->logicalLength == 0) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->logicalLength++;
}

/// Output each node in list
void al_for_each(arraylist *list, listIterator iterator) {
    assert(iterator != NULL);

    listNode *node = list->head;
    bool result = TRUE;
    while (node != NULL && result) {
        result = iterator(node->data);
        node = node->next;
    }
}

/// listIterator for list_for_each
bool iterate_int(void *data) {
    printf("Found value: %d\n", *(int *) data);
    return TRUE;
}

/// listIterator for list_for_each
bool iterate_string(void *data) {
    printf("Found string value: %s\n", *(char **) data);
    return TRUE;
}

///  returns the head of the list
void al_head(arraylist *list, void *element, bool removeFromList) {
    assert(list->head != NULL);

    listNode *node = list->head;
    memcpy(element, node->data, list->elementSize);

    if (removeFromList) {
        list->head = node->next;
        list->logicalLength--;

        free(node->data);
        free(node);
    }
}

/// returns the tail of the list
void al_tail(arraylist *list, void *element) {
    assert(list->tail != NULL);
    listNode *node = list->tail;
    memcpy(element, node->data, list->elementSize);
}

/// returns the number of items in the list
int al_size(arraylist *list) {
    return list->logicalLength;
}

/// return value at defined index
void *al_getAtIndex(arraylist *list, int i, const char* type) {
    void *val;
    arraylist _list;

    if (i < 0) {
        printf("Index cannot be below 0");
        exit(500);
    } else if (i > al_size(list)) {
        printf("Index Out of Range");
        exit(501);
    } else if (i == 0) {
        al_head(list, &val, 0);
    } else if (i == al_size(list)) {
        al_tail(list, &val);
    } else {
        if (type == STRING) {
            al_init(&_list, sizeof(char *), al_fstring);
            _list.head = list->head->next;
        } else if (type == INTERGER) {
            al_init(&_list, sizeof(int), NULL);
            _list.head = list->head->next;
        }

        for (int j = 1; j < i; j++) {
            _list.head = _list.head->next;
        }

        al_head(&_list, &val, 0);
    }
    return val;
}

/// delete the head of the list
void al_delHead(arraylist *list) {
    if (al_size(list) > 0) {
        listNode *current;

        current = list->head;
        list->head = current->next;

        if (list->freeFn) {
            list->freeFn(current->data);
        }

        free(current->data);
        free(current);
        list->logicalLength = --list->logicalLength;
    } else {
        printf("Cannot delete element from empty array\n");
        //exit(502); tolerance
    }
}

/// delete the tail of the list
void al_delTail(arraylist *list) {
    if (al_size(list) > 0) {
        listNode *current = list->head;

        while (current->next != list->tail)
            current = current->next;

        free(list->tail->data);
        free(list->tail);
        current->next = NULL;
        list->tail = current;
        list->logicalLength = --list->logicalLength;
    } else {
        printf("Cannot delete element from empty array\n");
        //exit(502); tolerance
    }
}

/// delete node at defined index
void al_delAtIndex(arraylist *list, int i) {

    if (i < 0) {
        printf("Index cannot be below 0");
        exit(500);
    } else if (i >= al_size(list)) {
        printf("Index Out of Range");
        exit(501);
    } else {
        listNode *prev_list = list->head;
        listNode *current = list->head->next;

        if (i == 0)
            al_delHead(list);
        else if (i == al_size(list)) {
            al_delTail(list);
        } else {
            for (int j = 1; j < i; j++) {
                prev_list = prev_list->next;
                current = current->next;
            }
            prev_list->next = current->next;
            free(current->data);
            free(current);

        }
    }
}

/// change node data at defined index
void al_setAtIndex(arraylist *list, int i, void *element) {
    int size = al_size(list);
    if (i < 0) {
        printf("Index cannot be below 0");
        exit(500);
    } else if (i > size) {
        printf("Index Out of Range");
        exit(501);
    } else if (size == 0) {
        printf("Cannot delete element from empty array\n");
        //exit(502); tolerance
    } else if (size > 0) {
        listNode *current = list->head;

        for (int j = 0; j < i; j++)
            current = current->next;

        memcpy(current->data, element, list->elementSize);
    }
}

/// convert arraylist to array
void al_toArray(arraylist *list, void *arr[], const char *type) {
    listNode *c = list->head;
    int size = al_size(list);

    if (type == INTERGER) {
        for (int i = 0; i < size; i++) {
            *((int *) (arr) + i) = *(int *) (c->data);
            c = c->next;
        }
    } else if (type == DOUBLE) {
        for (int i = 0; i < size; i++) {
            *((double *) (arr) + i) = *(double *) (c->data);
            c = c->next;
        }
    } else if (type == STRING) {
        for (int i = 0; i < size; i++) {
            *((char **) (arr) + i) = *(char **) (c->data);
            c = c->next;
        }
    } else {
        printf("error type\n");
        exit(510);
    }
}

/// sort array list
void al_sort(arraylist *list, char *type) {
    int size = al_size(list);
    int arr[size];

    al_toArray(list, (void **) arr, INTERGER);
    arr_sort((void **) arr, size, type);

    listNode *c = list->head;
    if (type == INTERGER) {
        for (int i = 0; i < size; i++) {
            *(int *) (c->data) = *((int *) (arr) + i);
            c = c->next;
        }
    } else if (type == DOUBLE) {
        for (int i = 0; i < size; i++) {
            *(double *) (c->data) = *((double *) (arr) + i);
            c = c->next;
        }
    } else if (type == STRING) {
        for (int i = 0; i < size; i++) {
            *(char **) (c->data) = *((char **) (arr) + i);
            c = c->next;
        }
    } else {
        printf("error type\n");
        exit(510);
    }
}

/// reverse array list
void al_inverse(arraylist *list,const char *type) {
    int size = al_size(list);
    int arr[size];

    al_toArray(list, (void **) arr, INTERGER);
    arr_inverse((void **) arr, size, type);

    listNode *c = list->head;

    if (type == INTERGER) {
        for (int i = 0; i < size; i++) {
            *(int *) (c->data) = *((int *) (arr) + i);
            c = c->next;
        }
    } else if (type == DOUBLE) {
        for (int i = 0; i < size; i++) {
            *(double *) (c->data) = *((double *) (arr) + i);
            c = c->next;
        }
    } else if (type == STRING) {
        for (int i = 0; i < size; i++) {
            *(char **) (c->data) = *((char **) (arr) + i);
            c = c->next;
        }
    } else {
        printf("error type\n");
        exit(510);
    }
}

/// search an element in arraylist
int al_contain(arraylist *list,void *target,const char *type){
    listNode *c = list->head;

    if (type == INTERGER) {
        for (int i = 0; i < al_size(list); ++i) {
            if( *(int *) (c->data) ==*(int *) target)
                return i;
            else
                c = c->next;
        }
    } else if (type == DOUBLE) {
        for (int i = 0; i < al_size(list); ++i) {
            if( *(double *) (c->data) ==*(double *) target)
                return i;
            else
                c = c->next;
        }
    } else if (type == STRING) {
        for (int i = 0; i < al_size(list); ++i) {
            if( *(char **) (c->data) == *(char **) target)
                return i;
            else
                c = c->next;
        }
    } else {
        printf("error type\n");
        exit(510);
    }

    return -1;
}


void al_fstring(void *data) {
    free(*(char **) data);
}

#endif //POWERC_ARRAYLIST_H
