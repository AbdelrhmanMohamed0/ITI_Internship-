#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "..\..\Libraries\graphics\graphics.h"
#include "Admin.h"

static u8 admin_password[ADMIN_PASSWORD_LENGTH] = "1234";
static u8 available_slots[NUM_OF_SLOTS] = {0};
static u32 position = 0;
static u8 slots_options[NUM_OF_SLOTS][15] =
    {
        "2pm to 2:30pm",
        "2:30pm to 3pm",
        "3pm to 3:30pm",
        "4pm to 4:30pm",
        "4:30pm to 5pm"};

ES_t Validate_Admin_Password(void)
{
    char adminPassword[ADMIN_PASSWORD_LENGTH];
    int attempts = 0;
    do
    {
        printf("Enter admin password: ");
        fflush(stdin);
        fflush(stdout);
        fgets(adminPassword, sizeof(adminPassword), stdin);
        fflush(stdin);
        fflush(stdout);
        adminPassword[strcspn(adminPassword, "\n")] = '\0'; // Remove trailing newline
        if (strcmp(adminPassword, admin_password) == 0)
        {
            Motion();
            printf("Password is correct\n");
            return ES_OK; // Password is correct
        }
        else
        {
            printf("Invalid password. %d attempts remaining.\n", NUM_OF_ADMIN_PASSWORD_TRIALS - attempts - 1);
            attempts++;
        }
    } while (attempts < NUM_OF_ADMIN_PASSWORD_TRIALS);
    return ES_NOT_OK; // Password is incorrect or maximum attempts reached
}

ES_t Add_new_patient_record(List *plist)
{
    ELEMENT_TYPE copy_patient;
    int check_result;
    u8 temp_gender[15];
    printf("Enter the patient ID: ");
    scanf("%d", &copy_patient.Patient.ID);
    printf("Enter the patient Gender: ");
    fflush(stdin);
    fflush(stdout);
    fgets(copy_patient.Patient.Gender, 15, stdin);
    fflush(stdin);
    fflush(stdout);
    copy_patient.Patient.Gender[strlen(copy_patient.Patient.Gender) - 1] = '\0';
    strcpy(temp_gender, copy_patient.Patient.Gender);
    printf("Enter the patient name: ");
    fflush(stdin);
    fflush(stdout);
    fgets(copy_patient.Patient.Name, 50, stdin);
    fflush(stdin);
    fflush(stdout);
    copy_patient.Patient.Name[strlen(copy_patient.Patient.Name) - 1] = '\0';
    printf("Enter the patient age: ");
    scanf("%d", &copy_patient.Patient.Age);
    printf("Enter the patient email: ");
    fflush(stdin);
    fflush(stdout);
    fgets(copy_patient.Patient.Email, 30, stdin);
    fflush(stdin);
    fflush(stdout);
    copy_patient.Patient.Email[strlen(copy_patient.Patient.Email) - 1] = '\0';
    printf("Enter the patient phone: ");
    fflush(stdin);
    fflush(stdout);
    fgets(copy_patient.Patient.Phone, 15, stdin);
    fflush(stdin);
    fflush(stdout);
    strcpy(copy_patient.Patient.Gender, temp_gender);
    copy_patient.Patient.Phone[strlen(copy_patient.Patient.Phone) - 1] = '\0';
    if (check_status(&copy_patient, plist) != ES_OK)
    {
        return check_status(&copy_patient, plist);
    }
    if (position >= 0)
    {
        check_result = search_position(plist, copy_patient);
    }
    if ((check_result != -1) && (position >= 0))
    {
        printf("Patient ID already exists\n");
        return ES_INVALID_ID;
    }
    else
    {
        if (insert_list(plist, copy_patient, position) == ES_OK)
        {
            Motion();
            printf("Patient added successfully\n");
            position++;
        }
        else
        {
            printf("Patient not added\n");
        }
    }
    return ES_OK;
}

ES_t Edit_patient_record(List *plist)
{
    ELEMENT_TYPE copy_patient;
    int pos = 0, choice = 0;
    printf("Enter the patient ID: ");
    scanf("%d", &copy_patient.Patient.ID);
    if (position >= 0)
    {
        pos = search_position(plist, copy_patient);
    }
    if ((pos == -1) && (position >= 0))
    {
        printf("Patient ID not found\n");
        return ES_INVALID_ID;
    }
    else
    {
        retrieve_list(plist, &copy_patient, pos);
        printf("1- Edit patient name\n");
        printf("2- Edit patient age\n");
        printf("3- Edit patient email\n");
        printf("4- Edit patient phone\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the patient name: ");
            fflush(stdin);
            fflush(stdout);
            fgets(copy_patient.Patient.Name, 50, stdin);
            fflush(stdin);
            fflush(stdout);
            copy_patient.Patient.Name[strlen(copy_patient.Patient.Name) - 1] = '\0';
            break;
        case 2:
            printf("Enter the patient age: ");
            scanf("%d", &copy_patient.Patient.Age);
            break;
        case 3:
            printf("Enter the patient email: ");
            fflush(stdin);
            fflush(stdout);
            fgets(copy_patient.Patient.Email, 30, stdin);
            fflush(stdin);
            fflush(stdout);
            copy_patient.Patient.Email[strlen(copy_patient.Patient.Email) - 1] = '\0';
            break;
        case 4:
            printf("Enter the patient phone: ");
            fflush(stdin);
            fflush(stdout);
            fgets(copy_patient.Patient.Phone, 15, stdin);
            fflush(stdin);
            fflush(stdout);
            copy_patient.Patient.Phone[strlen(copy_patient.Patient.Phone) - 1] = '\0';
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        if (check_status(&copy_patient, plist) != ES_OK)
        {
            return check_status(&copy_patient, plist);
        }
        if (replace_list(plist, copy_patient, pos))
        {
            Motion();
            printf("Patient edited successfully\n");
        }
        else
        {
            printf("Patient not edited\n");
        }
    }
    return ES_OK;
}

ES_t Reserve_slot_with_the_doctor(List *plist)
{
    ELEMENT_TYPE copy_patient, temp_patient;
    int pos = 0, slot_choice, flag = 0;
    printf("Enter the patient ID: ");
    scanf("%d", &copy_patient.Appointment.ID);
    temp_patient.Patient.ID = copy_patient.Appointment.ID;
    if (position >= 0)
    {
        pos = search_position(plist, temp_patient);
    }
    if ((pos == -1) && (position >= 0))
    {
        printf("Patient ID not found\n");
        return ES_INVALID_ID;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (available_slots[i] == 0)
            {
                if (flag == 0)
                {
                    printf("Available slots are:\n");
                    flag = 1;
                }
                printf("%d. %s\n", i + 1, slots_options[i]);
            }
        }
        if (flag == 0)
        {
            printf("No available slots\n");
            return ES_NO_AVAILABLE_SLOTS;
        }
        printf("Enter the slot choice: ");
        scanf("%d", &slot_choice);
        if (slot_choice < 1 || slot_choice > 5)
        {
            printf("Invalid slot choice\n");
            return ES_INVALID_SLOT;
        }
        else
        {
            available_slots[slot_choice - 1] = 1;
        }
        retrieve_list(plist, &copy_patient, pos);
        strcpy(copy_patient.Appointment.Slots, slots_options[slot_choice - 1]);
        replace_list(plist, copy_patient, pos);
        Motion();
        printf("Slot reserved successfully\n");
    }
    return ES_OK;
}

ES_t Cancel_reservation(List *plist)
{
    ELEMENT_TYPE copy_patient, temp_patient;
    u8 slot[20];
    int pos = 0, flag = 0;
    printf("Enter the patient ID: ");
    scanf("%d", &copy_patient.Appointment.ID);
    temp_patient.Patient.ID = copy_patient.Appointment.ID;
    if (position >= 0)
    {
        pos = search_position(plist, temp_patient);
    }
    if ((pos == -1) && (position >= 0))
    {
        printf("Patient ID not found\n");
        return ES_INVALID_ID;
    }
    else
    {
        retrieve_list(plist, &copy_patient, pos);
        strcpy(slot, copy_patient.Appointment.Slots);
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(slots_options[i], slot) == 0)
            {
                available_slots[i] = 0;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("Slot not found\n");
            return ES_INVALID_SLOT;
        }
        if (delete_list(plist, &copy_patient, pos) == ES_OK)
        {
            Motion();
            printf("Slot cancelled successfully\n");
        }
        else
        {
            printf("Slot not cancelled\n");
        }
    }
    position--;
    return ES_OK;
}

ES_t check_status(ELEMENT_TYPE *element, List *pList)
{
    if (element == NULL)
    {
        return ES_NULL_POINTER;
    }
    if (pList == NULL)
    {
        return ES_NULL_POINTER;
    }
    if (element->Patient.ID < 0)
    {
        return ES_INVALID_ID;
    }
    if (element->Patient.Age < 0)
    {
        return ES_INVALID_AGE;
    }
    if (strlen(element->Patient.Name) == 0)
    {
        return ES_INVALID_NAME;
    }
    if (strlen(element->Patient.Gender) == 0)
    {
        return ES_INVALID_GENDER;
    }
    if (strlen(element->Patient.Email) == 0)
    {
        return ES_INVALID_EMAIL;
    }
    if (strlen(element->Patient.Phone) == 0)
    {
        return ES_INVALID_PHONE;
    }
    return ES_OK;
}
