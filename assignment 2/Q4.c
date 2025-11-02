#include <stdio.h>

#define MAX 5

void push(int stack[], int *top) {
    int val;
    if (*top == MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &val);
    (*top)++;
    stack[*top] = val;
    printf("Element pushed.\n");
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow.\n");
        return;
    }
    printf("Popped element: %d\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display(int stack[], int top) {
	int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for ( i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[MAX];
    int top = -1, choice;
    do {
        printf("\n--- Stack Operations ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}
