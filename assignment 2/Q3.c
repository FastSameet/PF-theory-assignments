#include <stdio.h>

#define POWER_ON        (1 << 0)   
#define OVERLOAD        (1 << 1)   
#define MAINTENANCE     (1 << 2)  

void querySector(int grid[5][5], int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }
    int status = grid[r][c];
    printf("\nStatus for Sector [%d][%d]:\n", r, c);
    printf("Power: %s\n", (status & POWER_ON) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & OVERLOAD) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (status & MAINTENANCE) ? "YES" : "NO");
}

void updateSector(int grid[5][5], int rows, int cols) {
    int r, c, flag, action;
    printf("Enter row (0-%d): ", rows - 1);
    scanf("%d", &r);
    printf("Enter column (0-%d): ", cols - 1);
    scanf("%d", &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("\nChoose flag to modify:\n");
    printf("1. Power Status\n");
    printf("2. Overload Warning\n");
    printf("3. Maintenance Required\n");
    printf("Enter your choice: ");
    scanf("%d", &flag);

    printf("Enter action (1 = Set, 0 = Clear): ");
    scanf("%d", &action);

    int mask = 1 << (flag - 1);

    if (action == 1)
        grid[r][c] |= mask;  
    else
        grid[r][c] &= ~mask; 

    printf("Sector [%d][%d] updated successfully!\n", r, c);
}

void runDiagnostic(int grid[5][5], int rows, int cols) {
    int overloadCount = 0, maintenanceCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] & OVERLOAD)
                overloadCount++;
            if (grid[i][j] & MAINTENANCE)
                maintenanceCount++;
        }
    }

    printf("\n===== SYSTEM DIAGNOSTIC =====\n");
    printf("Total Sectors Overloaded: %d\n", overloadCount);
    printf("Total Sectors Requiring Maintenance: %d\n", maintenanceCount);
    printf("=================================\n");
}

int main() {
    int rows = 5, cols = 5;
    int grid[5][5] = {0};  

    int choice;

    do {
        printf("\n=== IESCO Power Grid Monitoring System ===\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSector(grid, rows, cols);
                break;
            case 2: {
                int r, c;
                printf("Enter row and column: ");
                scanf("%d %d", &r, &c);
                querySector(grid, rows, cols, r, c);
                break;
            }
            case 3:
                runDiagnostic(grid, rows, cols);
                break;

            case 4:
                printf("Exiting system... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select 1–4.\n");
        }

    } while (choice != 4);

    return 0;
}
