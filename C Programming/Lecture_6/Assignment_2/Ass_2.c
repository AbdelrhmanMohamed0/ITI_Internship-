/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<    Ass_2.c    >>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author     : Abdelrhman Mohamed Ellawendi
 *  Date       : 21/7/2024
 *  version    : v1.0
 *  require    : Create a program to manage employee records. Each employee has a name, ID, salary,
 *               and department. Use a union to store either the salary or the department for
 *               an employee, but not both.
 */
#include <stdio.h>
#include <string.h>
struct Employee
{
    char name[50];
    int id;
    union
    {
        float salary;
        char department[50];
    } info;
    int type; // 0 for salary, 1 for department
};
void addEmployee(struct Employee employees[], int *count);
void displayEmployees(struct Employee employees[], int count);
void findEmployee(struct Employee employees[], int count, int id);
void updateSalary(struct Employee employees[], int count, int id, float newSalary);
void listByDepartment(struct Employee employees[], int count, const char *department);
int main(void)
{
    int choice, id, count = 0;
    float newSalary;
    char department[50];
    struct Employee employees[100];
    do
    {
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Find Employee\n");
        printf("4. Update Salary\n");
        printf("5. List Employees by Department\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addEmployee(employees, &count);
            break;
        case 2:
            displayEmployees(employees, count);
            break;
        case 3:
            printf("Enter employee ID: ");
            scanf("%d", &id);
            findEmployee(employees, count, id);
            break;
        case 4:
            printf("Enter employee ID: ");
            scanf("%d", &id);
            printf("Enter new salary: ");
            scanf("%f", &newSalary);
            updateSalary(employees, count, id, newSalary);
            break;
        case 5:
            printf("Enter department: ");
            scanf("%s", department);
            listByDepartment(employees, count, department);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);
    return 0;
}
void addEmployee(struct Employee employees[], int *count)
{
    if (*count < 100)
    {
        printf("Enter employee name: ");
        scanf("%s", employees[*count].name);
        printf("Enter employee ID: ");
        scanf("%d", &employees[*count].id);
        printf("Enter employee type (0 for salary, 1 for department): ");
        scanf("%d", &employees[*count].type);
        if (employees[*count].type == 0)
        {
            printf("Enter employee salary: ");
            scanf("%f", &employees[*count].info.salary);
        }
        else if (employees[*count].type == 1)
        {
            printf("Enter employee department: ");
            scanf("%s", employees[*count].info.department);
        }
        else
        {
            printf("Invalid employee type. Please try again.\n");
            return;
        }
        (*count)++;
    }
    else
    {
        printf("Maximum number of employees reached.\n");
    }
}
void displayEmployees(struct Employee employees[], int count)
{
    printf("Employee Records:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("ID: %d\n", employees[i].id);
        if (employees[i].type == 0)
        {
            printf("Salary: %.2f\n", employees[i].info.salary);
        }
        else if (employees[i].type == 1)
        {
            printf("Department: %s\n", employees[i].info.department);
        }
        printf("\n");
    }
}
void findEmployee(struct Employee employees[], int count, int id)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (employees[i].id == id)
        {
            printf("Employee found:\n");
            printf("Name: %s\n", employees[i].name);
            printf("ID: %d\n", employees[i].id);
            if (employees[i].type == 0)
            {
                printf("Salary: %.2f\n", employees[i].info.salary);
            }
            else if (employees[i].type == 1)
            {
                printf("Department: %s\n", employees[i].info.department);
            }
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee not found.\n");
    }
}
void listByDepartment(struct Employee employees[], int count, const char *department)
{

    printf("Employees in department %s:\n", department);
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (employees[i].type == 1 && strcmp(employees[i].info.department, department) == 0)
        {
            printf("Name: %s\n", employees[i].name);
            printf("ID: %d\n", employees[i].id);
            printf("Department: %s\n", employees[i].info.department);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No employees found in department %s.\n", department);
    }
}

void updateSalary(struct Employee employees[], int count, int id, float newSalary)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (employees[i].id == id)
        {
            if (employees[i].type == 0)
            {
                employees[i].info.salary = newSalary;
                printf("Salary updated successfully.\n");
                found = 1;
                break;
            }
            else
            {
                printf("Employee is not of type salary.\n");
                found = 1;
                break;
            }
        }
    }
    if (!found)
    {
        printf("Employee not found.\n");
    }
}