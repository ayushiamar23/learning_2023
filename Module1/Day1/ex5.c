#include <stdio.h>

int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1:
            // Set 1st bit
            num |= (1 << 0);
            break;
        case 2:
            // Clear 31st bit
            num &= ~(1 << 31);
            break;
        case 3:
            // Toggle 16th bit
            num ^= (1 << 15);
            break;
        default:
            printf("Error: Invalid operation type.\n");
            break;
    }
    return num;
}

int main() {
    int number, operationType, result;

    printf("Enter an integer (32 bits): ");
    scanf("%d", &number);

    printf("Enter the operation type (1: Set 1st bit, 2: Clear 31st bit, 3: Toggle 16th bit): ");
    scanf("%d", &operationType);

    result = bit_operations(number, operationType);

    printf("Result: %d\n", result);

    return 0;
}
