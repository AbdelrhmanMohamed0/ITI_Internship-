#include <stdio.h> // For input/output functions
#include "List.h"  // Include header file
void display(ELEMENT_TYPE element);
int main(void)
{
    List ls;                          // Declare a queue variable
    ELEMENT_TYPE element, data, size; // Declare some variables to store elements, data, and size
    list_init(&ls);                   // Initialize the list
    insert_list(&ls, 8, 0);
    insert_list(&ls, 9, 1);
    insert_list(&ls, 10, 1);
    insert_list(&ls, 15, 1);
    insert_list(&ls, 17, 4);
    insert_list(&ls, 20, 2);
    insert_list(&ls, 22, 6);
    retrieve_list(&ls, &data, 1);            // Get an element of the list and store it in data
    printf("retrieved data is %d \n", data); // Print the data
    insert_list(&ls, 25, 3);
    delete_list(&ls, &data, 2);            // Pop an element from the list and store it in data
    printf("deleted data is %d \n", data); // Print the data
    replace_list(&ls, 50, 2);
    printf("------------------------ \n");
    printf("display list as queue \n");
    traverse_list_as_queue(&ls, &display); // Traverse the list and display each element
    printf("------------------------ \n");
    printf("display list as stack \n");
    traverse_list_as_stack(&ls, &display); // Traverse the list and display each element
    bubble_sort(&ls);                      // Sort the list
    printf("------------------------ \n");
    printf("list after sorting \n");
    traverse_list_as_queue(&ls, &display); // Traverse the list and display each element
    printf("------------------------ \n");
    data = get_position(&ls, 15);                // Get the position of an element
    printf("The position of 15 is %d \n", data); // Print the position
    size = size_list(&ls);                       // Get the size of the list and store it in size
    printf("List size is %d \n", size);          // Print the size
    clear_list(&ls);                             // Clear the list
    printf("the data has been erased \n");
    if (!delete_list(&ls, &data, 2)) // Try to pop an element from the empty list and check if it fails
        printf("Empty list \n");     // Print a message
    return 0;                        // Exit with success code
}
void display(ELEMENT_TYPE element){ 
    printf("%d \n", element); 
}
