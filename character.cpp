#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 52  // 26 lowercase + 26 uppercase

// Function to count the occurrence of each alphabetic character in the file
void count_characters(FILE *file) {
    int count[ALPHABET_SIZE] = {0};
    int c;

    // Read each character from the file and update the count
    while ((c = fgetc(file)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            count[c - 'A' + 26]++;
        }
    }

    // Print the count of each character
    printf("Character occurrences (a-z, A-Z):\n");
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("'%c': %d\n", 'a' + i, count[i]);
        }
    }
    for (int i = 26; i < ALPHABET_SIZE; i++) {
        if (count[i] > 0) {
            printf("'%c': %d\n", 'A' + (i - 26), count[i]);
        }
    }
}

int main() {
    const char *filename = "data.txt";
    FILE *file;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    count_characters(file);

    fclose(file);
    return 0;
}
