#include <stdio.h>
#include <string.h>

void customerInfo(char name[30], char cnic[20]) {
    printf("Enter your name: ");
    getchar(); 
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = '\0'; 

    printf("Enter your CNIC: ");
    fgets(cnic, 20, stdin);
    cnic[strcspn(cnic, "\n")] = '\0'; 

    printf("\nCustomer details added successfully!\n");
}

void displayInventory(int PCode[], int quantity[], float price[], int count) {
    printf("\n===== INVENTORY =====\n");
    printf("ProductCode\tQuantity\tPrice\n");
    printf("----------------------------------\n");
    int i;
    for ( i = 0; i < count; i++) {
        printf("%03d\t\t%d\t\t%.2f\n", PCode[i], quantity[i], price[i]);
    }
}

int findProduct(int PCode[], int count, int code) {
	int i;
    for (i = 0; i < count; i++) {
        if (PCode[i] == code)
            return i;
    }
    return -1; 
}

void addToCart(int PCode[], int quantity[], float price[],
               int cartCodes[], int cartQty[], int *cartCount, int count) {
    int code, qty;
    printf("Enter Product Code: ");
    scanf("%d", &code);

    int index = findProduct(PCode, count, code);
    if (index == -1) {
        printf("Invalid product code!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (qty > quantity[index]) {
        printf("Error: Only %d items available in stock.\n", quantity[index]);
        return;
    }

    quantity[index] -= qty;
    cartCodes[*cartCount] = code;
    cartQty[*cartCount] = qty;
    (*cartCount)++;

    printf("Item added to cart successfully!\n");
}

void displayBill(int cartCodes[], int cartQty[], float price[], int cartCount, float *total) {
    *total = 0;
    printf("\n===== CART SUMMARY =====\n");
    printf("Code\tQty\tPrice\tTotal\n");
    printf("--------------------------------\n");
		int i;
    for ( i = 0; i < cartCount; i++) {
        int code = cartCodes[i];
        float subtotal = price[code - 1] * cartQty[i];
        printf("%03d\t%d\t%.2f\t%.2f\n", code, cartQty[i], price[code - 1], subtotal);
        *total += subtotal;
    }

    printf("--------------------------------\n");
    printf("Total Bill: %.2f\n", *total);
}

void showInvoice(char name[30], char cnic[20], float total) {
    char promo[20];
    float discount = 0;

    printf("\nDo you have a promo code? (Enter 'Eid2025' for 25%% off, or 'no'): ");
    scanf("%s", promo);

    if (strcmp(promo, "Eid2025") == 0) {
        discount = total * 0.25;
        printf("Promo code applied! You saved %.2f\n", discount);
    }

    float finalBill = total - discount;

    printf("\n===== INVOICE =====\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("Total Bill (without discount): %.2f\n", total);
    printf("Final Bill (after discount): %.2f\n", finalBill);
    printf("==========================\n");
}


int main() {
    int PCode[100] = {1, 2, 3, 4};
    int quantity[100] = {50, 10, 20, 8};
    float price[100] = {100, 200, 300, 150};
    int count = 4; 

    int cartCodes[100];
    int cartQty[100];
    int cartCount = 0;

    char name[30], cnic[20];
    float total = 0;
    int choice;

    do {
        printf("\n=== SUPERMARKET MENU ===\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerInfo(name, cnic);
                break;
            case 2:
                displayInventory(PCode, quantity, price, count);
                break;
            case 3:
                addToCart(PCode, quantity, price, cartCodes, cartQty, &cartCount, count);
                break;
            case 4:
                displayBill(cartCodes, cartQty, price, cartCount, &total);
                break;
            case 5:
                showInvoice(name, cnic, total);
                break;
            case 6:
                printf("Exiting system... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please select from 1–6.\n");
        }
    } while (choice != 6);

    return 0;
}
