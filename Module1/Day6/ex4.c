#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortArray(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[j].marks > students[i].marks) {
                // Swap the structures if marks are in descending order
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void displayArray(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];

    // Assume the array has been initialized or filled with data

    printf("\nStudent Details (Before Sorting):\n");
    displayArray(students, size);

    sortArray(students, size);

    printf("\nStudent Details (After Sorting):\n");
    displayArray(students, size);

    return 0;
}
