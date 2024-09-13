#ifndef ERROR_STATES_H_
#define ERROR_STATES_H_

// Define a boolean type with values false (0) and true (1)
typedef enum
{
    false = 0,
    true
} bool;

// Define an enumeration for error states
typedef enum
{
    ES_NOT_OK,             // Operation not successful
    ES_OK,                 // Operation successful
    ES_INVALID_ID,         // Invalid ID provided
    ES_INVALID_AGE,        // Invalid age provided
    ES_INVALID_NAME,       // Invalid name provided
    ES_INVALID_EMAIL,      // Invalid email provided
    ES_INVALID_PHONE,      // Invalid phone number provided
    ES_INVALID_GENDER,     // Invalid gender provided
    ES_NULL_POINTER,       // Null pointer encountered
    ES_OUT_OF_RANGE,       // Value out of acceptable range
    ES_NO_AVAILABLE_SLOTS, // No available slots
    ES_INVALID_SLOT        // Invalid slot provided
} ES_t;

#endif