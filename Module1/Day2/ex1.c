#include <stdio.h>

void print_exponent(double num) {
    unsigned long long bits = *((unsigned long long*)&num);
    unsigned int exponent = (bits >> 52) & 0x7FF;

    printf("Exponent in hexadecimal: 0x%X\n", exponent);
    
    printf("Exponent in binary: 0b");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;

    print_exponent(x);

    return 0;
}
