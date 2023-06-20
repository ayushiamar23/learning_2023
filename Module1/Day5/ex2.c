#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    float real;
    float imag;
};

// Function to read a complex number
void readComplex(struct Complex* num) {
    printf("Enter the real part: ");
    scanf("%f", &(num->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(num->imag));
}

// Function to write a complex number
void writeComplex(const struct Complex* num) {
    if (num->imag >= 0) {
        printf("Complex number: %.2f + %.2fi\n", num->real, num->imag);
    } else {
        printf("Complex number: %.2f - %.2fi\n", num->real, -num->imag);
    }
}

// Function to add two complex numbers
struct Complex addComplex(const struct Complex* num1, const struct Complex* num2) {
    struct Complex result;
    result.real = num1->real + num2->real;
    result.imag = num1->imag + num2->imag;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(const struct Complex* num1, const struct Complex* num2) {
    struct Complex result;
    result.real = num1->real * num2->real - num1->imag * num2->imag;
    result.imag = num1->real * num2->imag + num1->imag * num2->real;
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    // Reading the first complex number
    printf("Reading the first complex number:\n");
    readComplex(&num1);

    // Reading the second complex number
    printf("Reading the second complex number:\n");
    readComplex(&num2);

    // Writing the complex numbers
    printf("\nFirst complex number:\n");
    writeComplex(&num1);
    printf("Second complex number:\n");
    writeComplex(&num2);

    // Adding the complex numbers
    sum = addComplex(&num1, &num2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(&sum);

    // Multiplying the complex numbers
    product = multiplyComplex(&num1, &num2);
    printf("\nProduct of the complex numbers:\n");
    writeComplex(&product);

    return 0;
}
