#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include "..\Libraries\STD_TYPES.h" // Include standard types header

// Structure to store patient information
typedef struct
{
    u32 ID;           // Patient ID
    u8 Age;           // Patient age
    u8 Gender[15];    // Patient gender
    u8 Name[50];      // Patient name
    u8 Email[30];     // Patient email
    u8 Phone[15];     // Patient phone number
} Patient_st;

// Structure to store appointment information
typedef struct
{
    u32 ID;           // Appointment ID
    u8 Slots[20];     // Appointment slots
} Appointment_st;

// Structure to store a record containing both patient and appointment information
typedef struct
{
    Patient_st Patient;       // Patient information
    Appointment_st Appointment; // Appointment information
} Record_st;

#endif // End of DATA_TYPES_H