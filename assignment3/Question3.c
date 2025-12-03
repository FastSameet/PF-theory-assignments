#include <stdio.h>
#include <string.h>

struct employee {
    int E_ID;
    char firstname[20];
    char lastname[20];
    char designation[20];
    int salary;
};

void display(int n, struct employee arr[n]) {
    int i;
    printf("\n--- EMPLOYEE DETAILS ---\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Name        : %s %s\n", arr[i].firstname, arr[i].lastname);
        printf("Employee ID : %d\n", arr[i].E_ID);
        printf("Designation : %s\n", arr[i].designation);
        printf("Salary      : %d\n", arr[i].salary);
    }
}

void highestsalary(int n, struct employee arr[n]) {
    int i;
    int highestIndex = 0;

    for (i = 1; i < n; i++) {
        if (arr[i].salary > arr[highestIndex].salary) {
            highestIndex = i;
        }
    }

    printf("\n--- EMPLOYEE WITH HIGHEST SALARY ---\n");
    printf("Name        : %s %s\n", arr[highestIndex].firstname, arr[highestIndex].lastname);
    printf("Employee ID : %d\n", arr[highestIndex].E_ID);
    printf("Designation : %s\n", arr[highestIndex].designation);
    printf("Salary      : %d\n", arr[highestIndex].salary);
}

void search(int n, struct employee arr[n]) {
    int choice, i;
    int ID;
    char name[20];

    printf("\n--- SEARCH EMPLOYEE ---\n");
    printf("1. Search by ID\n2. Search by First Name\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Enter Employee ID: ");
        scanf("%d", &ID);

        for (i = 0; i < n; i++) {
            if (ID == arr[i].E_ID) {
                printf("\nEmployee Found:\n");
                printf("Name        : %s %s\n", arr[i].firstname, arr[i].lastname);
                printf("Employee ID : %d\n", arr[i].E_ID);
                printf("Designation : %s\n", arr[i].designation);
                printf("Salary      : %d\n", arr[i].salary);
                return;
            }
        }
        printf("No employee found with ID %d.\n", ID);
        break;

    case 2:
        printf("Enter First Name: ");
        scanf("%s", name);

        for (i = 0; i < n; i++) {
            if (strcmp(name, arr[i].firstname) == 0) {
                printf("\nEmployee Found:\n");
                printf("Name        : %s %s\n", arr[i].firstname, arr[i].lastname);
                printf("Employee ID : %d\n", arr[i].E_ID);
                printf("Designation : %s\n", arr[i].designation);
                printf("Salary      : %d\n", arr[i].salary);
                return;
            }
        }
        printf("No employee found with name %s.\n", name);
        break;

    default:
        printf("Invalid choice.\n");
        break;
    }
}

void salaryincrement(int n, struct employee arr[n]) {
    int i;
    float increment;

    for (i = 0; i < n; i++) {
        if (arr[i].salary <= 50000) {
            increment = 0.10 * arr[i].salary;
            arr[i].salary += increment;
        }
    }

    printf("\nSalaries updated (10%% increment for salaries = 50000).\n");
}

int main() {
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee arr[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Employee %d ---\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &arr[i].E_ID);

        printf("First Name: ");
        scanf("%s", arr[i].firstname);

        printf("Last Name: ");
        scanf("%s", arr[i].lastname);

        printf("Designation: ");
        scanf("%s", arr[i].designation);

        printf("Salary: ");
        scanf("%d", &arr[i].salary);
    }

    display(n, arr);
    search(n, arr);
    highestsalary(n, arr);
    salaryincrement(n, arr);

    printf("\n--- FINAL EMPLOYEE LIST AFTER INCREMENT ---\n");
    display(n, arr);

    return 0;
}
