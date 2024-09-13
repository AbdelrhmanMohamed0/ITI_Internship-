#include <stdio.h>    // Standard input/output library
#include <stdlib.h>   // Standard library for general-purpose functions
#include <unistd.h>   // POSIX operating system API for sleep function
#include "graphics.h" // Header file for graphics functions

// Function to clear the screen
void clearScreen()
{
    system("cls"); // Use system call to clear the screen (specific to Windows)
}

// Function to delay execution for a specified number of milliseconds
// Parameters:
//   milliseconds - the number of milliseconds to delay
void delay(int milliseconds)
{
    usleep(milliseconds * 1000); // usleep takes time in microseconds, so we multiply milliseconds by 1000
}

// Function to display a loading motion
void Motion(void)
{
    printf("Please wait "); // Print initial message
    for(int i = 0; i < 15; i++) // Loop to simulate loading
    {
        printf("."); // Print a dot
        delay(100);  // Delay for 100 milliseconds
    }
    printf("\n"); // Print a newline after loading is complete
}