#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int evenSum = 0;
    int oddSum = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }

    int difference = evenSum - oddSum;

    printf("Sum of even-indexed elements: %d\n", evenSum);
    printf("Sum of odd-indexed elements: %d\n", oddSum);
    printf("Difference between even-indexed and odd-indexed elements: %d\n", difference);

    return 0;
}