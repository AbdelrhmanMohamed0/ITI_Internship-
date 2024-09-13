#ifndef ADMIN_H
#define ADMIN_H

#include "..\..\data_base\List.h" // Include the list header for list operations

// Define the number of admin options available
#define NUM_OF_ADMIN_OPTIONS 4

// Define the number of password trials allowed for admin
#define NUM_OF_ADMIN_PASSWORD_TRIALS 3

// Define the length of the admin password
#define ADMIN_PASSWORD_LENGTH 10

// Define the number of available slots for reservations
#define NUM_OF_SLOTS 5

// Function to validate the admin password
// Returns:
//   ES_t - error state indicating success or type of failure
ES_t Validate_Admin_Password(void);

// Function to add a new patient record to the list
// Parameters:
//   plist - pointer to the list of patients
// Returns:
//   ES_t - error state indicating success or type of failure
ES_t Add_new_patient_record(List *plist);

// Function to edit an existing patient record in the list
// Parameters:
//   plist - pointer to the list of patients
// Returns:
//   ES_t - error state indicating success or type of failure
ES_t Edit_patient_record(List *plist);

// Function to reserve a slot with the doctor for a patient
// Parameters:
//   plist - pointer to the list of patients
// Returns:
//   ES_t - error state indicating success or type of failure
ES_t Reserve_slot_with_the_doctor(List *plist);

// Function to cancel a reservation for a patient
// Parameters:
//   plist - pointer to the list of patients
// Returns:
//   ES_t - error state indicating success or type of failure
ES_t Cancel_reservation(List *plist);

// Function to check the status of a patient
// Parameters:
//   element - pointer to the patient element
//   pList - pointer to the list of patients
// Returns:
//   ES_t - error state indicating success or type of failure
ES_t check_status(ELEMENT_TYPE *element, List *pList);

#endif // End of ADMIN_H