#include <stdio.h>

void printBits(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        unsigned int mask = 1 << i;
        printf("%d", (num & mask) ? 1 : 0);
    }
    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Binary representation: ");
    printBits(num);

    return 0;
}
