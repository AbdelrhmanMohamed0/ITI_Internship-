// List.c: Source file for list implementation using linked_list in C

#include "List.h"   // Include header file
#include <stdio.h>  // For input/output functions
#include <stdlib.h> // For dynamic memory allocation

// Initialize the list
void list_init(List *plist)
{
    plist->size = 0;
    plist->current_pos = -1;
    plist->head = NULL;
    plist->current = NULL;
}

// Check if a list is full
bool list_full(List *plist)
{
    return (false);
}

// Check if a list is empty
bool list_empty(List *plist)
{
    return (!plist->size);
}

// insert an element to the list
bool insert_list(List *plist, ELEMENT_TYPE element, int pos)
{
    if ((pos < 0) || (pos >= (plist->size + 1)) || list_full(plist))
    {
        return false;
    }
    List_Node *ptr = (List_Node *)malloc(sizeof(List_Node));
    ptr->data = element;
    ptr->next = NULL;
    ptr->previous = NULL;
    if (pos == 0)
    {
        ptr->next = plist->head;
        if (plist->head)
        {
            plist->head->previous = ptr;
        }
        plist->head = ptr;
        plist->current = plist->head;
        plist->current_pos = 0;
        ptr->previous = NULL;
    }
    else
    {
        if (pos <= plist->current_pos)
        {
            while (plist->current_pos != pos)
            {
                plist->current = plist->current->previous;
                plist->current_pos--;
            }
            ptr->next = plist->current;
            ptr->previous = plist->current->previous;
            plist->current->previous->next = ptr;
            plist->current->previous = ptr;
            plist->current = ptr;
        }
        else
        {
            while (plist->current_pos != pos)
            {
                if (!(plist->current->next))
                {
                    ptr->next = NULL;
                    ptr->previous = plist->current;
                    plist->current->next = ptr;
                    plist->current = ptr;
                }
                else
                {
                    if (plist->current_pos == pos - 1)
                    {
                        ptr->next = plist->current->next;
                        ptr->next->previous = ptr;
                        plist->current->next = ptr;
                        ptr->previous = plist->current;
                        plist->current = ptr;
                    }
                    else
                    {
                        plist->current = plist->current->next;
                    }
                }
                plist->current_pos++;
            }
        }
    }
    plist->size++;
    return true;
}

// delete an element from the list
bool delete_list(List *plist, ELEMENT_TYPE *element, int pos)
{
    if (pos < 0 || pos >= plist->size || list_empty(plist))
    {
        return false;
    }
    List_Node *ptr;
    if (pos == 0)
    {
        plist->current = plist->head;
        *element = plist->current->data;
        plist->head = plist->current->next;
        free(plist->current);
        plist->current = plist->head;
        plist->current_pos = 0;
    }
    else
    {
        List_Node *ptr = NULL;
        while (plist->current_pos != pos)
        {
            if (pos <= plist->current_pos)
            {
                plist->current = plist->current->previous;
                plist->current_pos--;
            }
            else
            {
                plist->current = plist->current->next;
                plist->current_pos++;
            }
        }
        *element = plist->current->data;
        ptr = plist->current->previous;
        ptr->next = plist->current->next;
        if (plist->current->next)
        {
            plist->current->next->previous = ptr;
        }
        free(plist->current);
        plist->current = ptr;
        plist->current_pos = pos - 1;
    }
    plist->size--;
    return true;
}

// Get element from the list
bool retrieve_list(List *plist, ELEMENT_TYPE *element, int pos)
{
    if (pos < 0 || pos >= plist->size || list_empty(plist))
    {
        return false;
    }
    else
    {
        if (pos >= plist->current_pos)
        {
            while (plist->current_pos != pos)
            {
                plist->current = plist->current->next;
                plist->current_pos++;
            }
            *element = plist->current->data;
        }
        else
        {
            while (plist->current_pos != pos)
            {
                plist->current = plist->current->previous;
                plist->current_pos--;
            }
            *element = plist->current->data;
        }
        return true;
    }
}
// Replace an element from the list at a given position.
bool replace_list(List *plist, ELEMENT_TYPE element, int pos)
{
    if ((pos < 0) || (pos >= plist->size) || list_empty(plist))
    {
        return false;
    }
    List_Node *ptr = plist->current;
    if (pos >= plist->current_pos)
    {
        for (int i = plist->current_pos; i < pos; i++)
        {
            ptr = ptr->next;
        }
        ptr->data = element;
    }
    else
    {
        for (int i = plist->current_pos; i > pos; i--)
        {
            ptr = ptr->previous;
        }
        ptr->data = element;
    }

    return true;
}
// Traverse a list as stack and apply a function to each element
void traverse_list_as_stack(List *plist, void (*func)(ELEMENT_TYPE))
{
    if (!list_empty(plist))
    {
        List_Node *ptr1 = plist->current;
        while (ptr1->next)
        {
            ptr1 = ptr1->next;
        }
        while (ptr1)
        {
            func(ptr1->data);
            ptr1 = ptr1->previous;
        }
    }
}

// Traverse a list as queue and apply a function to each element
void traverse_list_as_queue(List *plist, void (*func)(ELEMENT_TYPE))
{
    if (!list_empty(plist))
    {
        List_Node *ptr = plist->head;
        while (ptr)
        {
            func(ptr->data);
            ptr = ptr->next;
        }
    }
}

int search_position(List *plist, ELEMENT_TYPE element)
{
    if (!list_empty(plist))
    {
        List_Node *ptr = plist->head;
        int index = 0;
        while (ptr)
        {
            if (ptr->data.Patient.ID == element.Patient.ID)
            {
                return index;
            }
            ptr = ptr->next;
            index++;
        }
    }
    return -1;
}

// Get the size of the list
u32 size_list(List *plist)
{
    return (plist->size);
}

// Clear the list

void clear_list(List *plist)
{
    plist->current = plist->head;
    while (plist->head)
    {
        plist->current = plist->head->next;
        free(plist->head);
        plist->head = plist->current;
    }
    plist->size = 0;
    plist->current_pos = -1;
    plist->current = NULL;
}
