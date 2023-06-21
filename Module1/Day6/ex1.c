#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to parse the string and initialize an array of structures
void parseString(const char* input, struct Student* students, int size) {
    char* token;
    char temp[20];

    for (int i = 0; i < size; i++) {
        // Parse the string using strtok
        token = strtok((char*)input, " ");
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        // Move to the next input in the string
        input = strchr(input, '\n');
        if (input != NULL) {
            input++;
        }
    }
}

int main() {
    int size;

    // Get the number of inputs/size of the array from the user
    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Clear input buffer
    while (getchar() != '\n');

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get input string from the user
    printf("Enter the student details (rollno name marks):\n");
    char input[50 * size];
    fgets(input, sizeof(input), stdin);

    // Remove the trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Parse the input string and initialize the array of structures
    parseString(input, students, size);

    // Display the initialized array of structures
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
