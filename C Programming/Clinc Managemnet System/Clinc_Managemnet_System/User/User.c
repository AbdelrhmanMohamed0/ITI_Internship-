#include <stdio.h>                             // Standard input/output library
#include <stdlib.h>                            // Standard library for general-purpose functions
#include "..\..\Libraries\graphics\graphics.h" // Include graphics header for screen and delay functions
#include "User.h"                              // Include user header for function declarations and types

// Function to view a specific patient's record
// Parameters:
//   plist - pointer to the list of patients
// Returns:
//   ES_t - error state indicating success or type of failure
ES_t View_patient_record(List *plist)
{
    ELEMENT_TYPE copy_patient; // Temporary storage for patient data
    int pos = 0;               // Position of the patient in the list

    // Prompt user to enter patient ID
    printf("Enter the patient ID: ");
    scanf("%d", &copy_patient.Patient.ID);

    // Search for the patient position in the list
    pos = search_position(plist, copy_patient);
    if (pos == -1)
    {
        // If patient ID not found, print message and return error state
        printf("Patient ID not found\n");
        return ES_INVALID_ID;
    }
    else
    {
        // If patient ID found, retrieve patient data from the list
        retrieve_list(plist, &copy_patient, pos);
        Motion(); // Display loading motion

        // Print patient details
        printf("Patient ID: %d\n", copy_patient.Patient.ID);
        printf("Patient Gender: %s\n", copy_patient.Patient.Gender);
        printf("Patient Name: %s\n", copy_patient.Patient.Name);
        printf("Patient Age: %d\n", copy_patient.Patient.Age);
        printf("Patient Email: %s\n", copy_patient.Patient.Email);
        printf("Patient Phone: %s\n", copy_patient.Patient.Phone);
    }
}

// Function to view today's reservations
// Parameters:
//   plist - pointer to the list of patients
void View_today_reservations(List *plist)
{
    ELEMENT_TYPE copy_patient; // Temporary storage for patient data
    int i;                     // Loop counter

    Motion(); // Display loading motion

    // Loop through the list of patients
    for (i = 0; i < size_list(plist); i++)
    {
        // Retrieve patient data from the list
        retrieve_list(plist, &copy_patient, i);

        // Print patient details and appointment slot
        printf("Patient number %d\n", i + 1);
        printf("Patient ID: %d\n", copy_patient.Patient.ID);
        printf("Patient Name: %s\n", copy_patient.Patient.Name);
        printf("Patient Gender: %s\n", copy_patient.Patient.Gender);
        printf("Patient Age: %d\n", copy_patient.Patient.Age);
        printf("Patient Email: %s\n", copy_patient.Patient.Email);
        printf("Patient Phone: %s\n", copy_patient.Patient.Phone);
        printf("Appointment Slot: %s\n", copy_patient.Appointment.Slots);
        printf("-------------------------\n");
    }

    // If no reservations, print message
    if (size_list(plist) == 0)
    {
        printf("No reservations today\n");
    }
}