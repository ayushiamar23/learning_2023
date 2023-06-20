#include <stdio.h>

// Structure to store person details
struct Person {
    char name[50];
    int age;
};

// Function to swap the fields of two structures
void swapFields(struct Person* p1, struct Person* p2) {
    // Swap the name field
    char tempName[50];
    strcpy(tempName, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, tempName);

    // Swap the age field
    int tempAge = p1->age;
    p1->age = p2->age;
    p2->age = tempAge;
}

int main() {
    struct Person person1, person2;

    // Read details for person 1
    printf("Enter details for person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &person1.age);

    // Read details for person 2
    printf("\nEnter details for person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &person2.age);

    printf("\nBefore swapping:\n");
    printf("Person 1: Name = %s, Age = %d\n", person1.name, person1.age);
    printf("Person 2: Name = %s, Age = %d\n", person2.name, person2.age);

    // Swap the fields using the swapFields function
    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1: Name = %s, Age = %d\n", person1.name, person1.age);
    printf("Person 2: Name = %s, Age = %d\n", person2.name, person2.age);

    return 0;
}
