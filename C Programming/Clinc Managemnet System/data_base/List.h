// Include guard to prevent multiple inclusion
#ifndef LIST_H
#define LIST_H

#include "..\Libraries\STD_TYPES.h"
#include "..\Libraries\ERROR_STATES.h"
#include "data_types.h"

#define ELEMENT_TYPE Record_st // Type of elements in the LIST

// Structure for LIST
typedef struct list_node
{
    ELEMENT_TYPE data;
    struct list_node *next;
    struct list_node *previous;
} List_Node;

typedef struct list
{
    List_Node *head, *current;
    int size, current_pos;
} List;

// Function prototypes

// Initialize the list
void list_init(List *plist);

// Check if a list is full
bool list_full(List *plist);

// Check if a list is empty
bool list_empty(List *plist);

// insert an element to the list
bool insert_list(List *plist, ELEMENT_TYPE element, int pos);

// delete an element from the list
bool delete_list(List *plist, ELEMENT_TYPE *element, int pos);

// Get element from the list
bool retrieve_list(List *plist, ELEMENT_TYPE *element, int pos);

// Replace an element from the list
bool replace_list(List *plist, ELEMENT_TYPE element, int pos);

// Traverse the list as queue and apply a function to each element
void traverse_list_as_queue(List *plist, void (*func)(ELEMENT_TYPE));

// Traverse the list as stack and apply a function to each element
void traverse_list_as_stack(List *plist, void (*func)(ELEMENT_TYPE));

// search the position of an element
int search_position(List *plist, ELEMENT_TYPE element);

// Get the size of the list
u32 size_list(List *plist);

// Clear the list
void clear_list(List *plist);

#endif
