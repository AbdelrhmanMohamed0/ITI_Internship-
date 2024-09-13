#ifndef USER_H
#define USER_H

// Include the header file for the List data structure
#include "..\..\data_base\List.h"

// Function to view a patient's record
// Parameters:
// - plist: Pointer to the list of patient records
// Returns:
// - ES_t: Status code indicating success or failure
ES_t View_patient_record(List *plist);

// Function to view today's reservations
// Parameters:
// - plist: Pointer to the list of patient records
void View_today_reservations(List *plist);

#endif // USER_H