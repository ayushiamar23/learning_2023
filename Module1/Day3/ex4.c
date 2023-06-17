#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;
    
    for (int i = 0; i < 4; i++) {
        int divisor = 1;
        int tempNum = num;

        // Remove the i-th digit from the number
        for (int j = 0; j < i; j++) {
            divisor *= 10;
        }
        tempNum = tempNum / (divisor * 10) * divisor + tempNum % divisor;

        if (tempNum > largest) {
            largest = tempNum;
        }
    }
    
    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNumber = findLargestNumber(num);

    printf("Largest number after deleting a single digit: %d\n", largestNumber);

    return 0;
}
