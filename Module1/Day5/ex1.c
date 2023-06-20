#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

float calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

float calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width +
                boxPtr->width * boxPtr->height +
                boxPtr->height * boxPtr->length);
}

int main() {
    struct Box box;
    struct Box* boxPtr = &box;

    // Accessing structure members using the asterisk (*) and dot (.) operators
    (*boxPtr).length = 2.5;
    (*boxPtr).width = 3.0;
    (*boxPtr).height = 4.0;

    // Accessing structure members using the arrow (->) operator
    boxPtr->length = 2.5;
    boxPtr->width = 3.0;
    boxPtr->height = 4.0;

    float volume = calculateVolume(boxPtr);
    float surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Box Volume: %.2f\n", volume);
    printf("Box Surface Area: %.2f\n", surfaceArea);

    return 0;
}
