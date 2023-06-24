#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void convertToUpperCase(char* str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void convertToLowerCase(char* str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void convertToPureUpperCase(char* str) {
    while (*str) {
        if (islower((unsigned char)*str)) {
            *str = toupper((unsigned char)*str);
        }
        str++;
    }
}

void copyFile(FILE* source, FILE* target, int option) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        if (option == 0) {
            fwrite(buffer, 1, bytesRead, target);
        } else if (option == 1) {
            convertToUpperCase(buffer);
            fwrite(buffer, 1, bytesRead, target);
        } else if (option == 2) {
            convertToLowerCase(buffer);
            fwrite(buffer, 1, bytesRead, target);
        } else if (option == 3) {
            convertToPureUpperCase(buffer);
            fwrite(buffer, 1, bytesRead, target);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [option] source_file target_file\n", argv[0]);
        return 1;
    }

    int option = 0; // 0 - Normal copy, 1 - Uppercase, 2 - Lowercase, 3 - Pure uppercase

    if (argc >= 4) {
        char *optionFlag = argv[1];
        if (optionFlag[0] == '-') {
            if (optionFlag[1] == 'u') {
                option = 1;
            } else if (optionFlag[1] == 'l') {
                option = 2;
            } else if (optionFlag[1] == 's') {
                option = 3;
            }
        }
    }

    FILE *sourceFile, *targetFile;
    sourceFile = fopen(argv[argc - 2], "rb");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    targetFile = fopen(argv[argc - 1], "wb");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    copyFile(sourceFile, targetFile, option);

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
