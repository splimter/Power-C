//
// Created by splimter on 15/12/2019.
// origin work pseudomuto
//
/// @details
/// Always init the list using: al_init
/// Always destroy the list using: al_destroy
/// C operation: al_append, al_prepend, al_toArray
/// R operation: al_getAtIndex, al_contains
/// U operation: al_setAtIndex, al_sort, al_reverse
/// D operation: al_delAtIndex, al_delHead, al_delTail
/// get arraylist size: al_size

/// @warning
/// 500 Index cannot be below 0
/// 501 Index Out of Range
/// 502 Empty Array X tolerated

// a common function used to free malloc'd objects
typedef void (*freeFunction)(void *);

typedef enum {
    FALSE, TRUE
} bool;

typedef bool (*listIterator)(void *);

typedef struct _listNode {
    void *data;
    struct _listNode *next;
} listNode;

typedef struct {
    int logicalLength;
    int elementSize;
    listNode *head;
    listNode *tail;
    freeFunction freeFn;
} arraylist;


/// Initializes a linked list
/// @param list - to be init: &list
/// @param elementSize - element size: sizeof(E)
/// @param freeFn - int: NULL, string: al_fstring
void al_init(arraylist *list, int elementSize, freeFunction freeFn);

/// Frees dynamically allocated nodes
/// @param list - &list
void al_destroy(arraylist *list);

///  Adds a node to the head of the list
/// \param list  - &list
/// \param element - &E
void al_prepend(arraylist *list, void *element);

/// Adds a node to the tail of the list
/// \param list - &list
/// \param element - &E
void al_append(arraylist *list, void *element);

/// print out each node in list
/// \param list - &list
/// \param iterator - type: iterate_type,
void al_for_each(arraylist *list, listIterator iterator);

/// listIterator for list_for_each
bool iterate_int(void *data);

/// listIterator for list_for_each
bool iterate_string(void *data);

///  returns the head of the list
/// \param list - &list
/// \param element - hold the head value
/// \param removeFromList - remove head
void al_head(arraylist *list, void *element, bool removeFromList);

/// returns the tail of the list
/// \param list - &list
/// \param element - hold the head value
void al_tail(arraylist *list, void *element);

/// returns the number of items in the list
/// \param list - &list
/// \return size of list
int al_size(arraylist *list);

void al_fstring(void *data);

/// delete the tail of list
/// @param list - &list
void al_delTail(arraylist *list);

/// return value at defined index
/// \param list - &list
/// \param i - index
/// \param type - Integer, Float, String
/// \return value at index
void *al_getAtIndex(arraylist *list, int i, const char *type);

/// delete the head of the list
/// \param list - &list
void al_delHead(arraylist *list);

/// delete the tail of the list
/// \param list - &list
void al_delTail(arraylist *list);

/// delete node at defined index
/// \param list - &list
/// \param i - index
void al_delAtIndex(arraylist *list, int i);

/// change node data at defined index
/// \param list - &list
/// \param i - index
/// \param element - data: &E
void al_setAtIndex(arraylist *list, int i, void *element);

/// convert arraylist to array
/// \param list - &list
/// \param arr - list item will go to it
/// \param type - Integer, Float, String
void al_toArray(arraylist *list, void *arr[], const char *type);

/// sort array list
/// \param list - &list
/// \param type - Integer, Float, String
void al_sort(arraylist *list, char *type);

/// reverse array list
/// \param list - &list
/// \param type - Integer, Float, String
void al_inverse(arraylist *list, const char *type);

/// search an element in arraylist
/// \param list - &list
/// \param target - &E
/// \return the index of element if found else -1
int al_contains(arraylist *list, void *target, const char *type);


void al_fstring(void *data);
