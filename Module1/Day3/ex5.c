#include <stdio.h>

void findMinMaxDigits(int n, int numbers[]) {
    int smallestDigit = 9;
    int largestDigit = 0;

    for (int i = 0; i < n; i++) {
        int temp = numbers[i];

        while (temp != 0) {
            int digit = temp % 10;

            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            temp /= 10;
        }
    }

    if (smallestDigit == 9 && largestDigit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter the numbers:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    findMinMaxDigits(n, numbers);

    return 0;
}
