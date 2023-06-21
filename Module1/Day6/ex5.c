#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchByName(const struct Student* students, int size, const char* name) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", name);
    }
}

int main() {
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];

    // Assume the array has been initialized or filled with data

    char searchName[20];
    printf("\nEnter the name of the student to search: ");
    scanf("%s", searchName);

    searchByName(students, size, searchName);

    return 0;
}
