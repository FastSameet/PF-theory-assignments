#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    int i;
    for ( i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toggleBits(char *ch) {
    *ch ^= (1 << 1);
    *ch ^= (1 << 4);
}

void encodeMessage(char message[]) {
    reverseString(message);
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        toggleBits(&message[i]);
    }
    printf("Encoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
	int i;
    for (i = 0; message[i] != '\0'; i++) {
        toggleBits(&message[i]);
    }
    reverseString(message);
    printf("Decoded Message: %s\n", message);
}

int main() {
    char message[200];
    int choice;
    do {
        printf("\n--- TCS Secure Message System ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter message to encode: ");
                fgets(message, 200, stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message);
                break;
            case 2:
                printf("Enter message to decode: ");
                fgets(message, 200, stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;
            case 3:
                printf("Exiting System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}
