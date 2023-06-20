#include <stdio.h>
#include <stdlib.h>

// Structure to store student data
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n;
    struct Student* students;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of students
    students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter the name: ");
        scanf("%s", students[i].name);

        printf("Enter the roll number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter the marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display data for each student
    printf("\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
