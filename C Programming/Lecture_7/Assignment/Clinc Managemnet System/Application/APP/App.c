#include <stdio.h>
#include "..\..\Clinc_Managemnet_System\Admin\Admin.h"
#include "..\..\Clinc_Managemnet_System\User\User.h"
#include "..\..\Libraries\graphics\graphics.h"

// Global list to store patient records and reservations
List list;

int main()
{
    u8 choice, mode;
    ES_t check;

    // Infinite loop to keep the program running until the user chooses to exit
    while (1)
    {
        delay(2000);
        clearScreen();

        // Display the main menu
        printf("Enter the mode: \n");
        printf("1- Admin Mode\n");
        printf("2- User Mode\n");
        printf("3- Exit\n");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            delay(100);
            clearScreen();
            // Validate admin password
            check = Validate_Admin_Password();
            if (check == ES_OK)
            {
                // Admin operations menu
                do
                {
                    delay(100);
                    clearScreen();
                    printf("Enter the operation you want to do: \n");
                    printf("1- Add new patient record\n");
                    printf("2- Edit patient record\n");
                    printf("3- Reserve a slot with the doctor\n");
                    printf("4- Cancel reservation\n");
                    printf("5- Go back\n");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        // Add a new patient record
                        Add_new_patient_record(&list);
                        delay(100);
                        break;
                    case 2:
                        // Edit an existing patient record
                        Edit_patient_record(&list);
                        delay(100);
                        break;
                    case 3:
                        // Reserve a slot with the doctor
                        Reserve_slot_with_the_doctor(&list);
                        delay(100);
                        break;
                    case 4:
                        // Cancel a reservation
                        Cancel_reservation(&list);
                        delay(100);
                        break;
                    case 5:
                        // Go back to the main menu
                        break;
                    default:
                        // Handle invalid choices
                        printf("Invalid choice\n");
                        delay(100);
                        break;
                    }
                } while (choice != 5);
            }
            else
            {
                // Handle invalid admin password
                printf("Invalid password\n");
                delay(100);
            }
            break;

        case 2:
            delay(100);
            clearScreen();
            // User operations menu
            do
            {
                printf("Enter the operation you want to do: \n");
                printf("1- View patient record\n");
                printf("2- View today's reservations\n");
                printf("3- Go back\n");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    // View a patient record
                    delay(100);
                    clearScreen();
                    View_patient_record(&list);
                    break;
                case 2:
                    // View today's reservations
                    delay(100);
                    clearScreen();
                    View_today_reservations(&list);
                    break;
                case 3:
                    // Go back to the main menu
                    break;
                default:
                    // Handle invalid choices
                    printf("Invalid choice\n");
                    delay(100);
                    break;
                }
            } while (choice != 3);
            break;

        case 3:
            // Exit the program
            delay(100);
            clearScreen();
            printf("Goodbye\n");
            return 0;

        default:
            // Handle invalid mode choices
            printf("Invalid choice\n");
            delay(100);
            break;
        }
    }
    return 0;
}