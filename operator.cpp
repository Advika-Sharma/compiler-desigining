#include <stdio.h>
#include <ctype.h>
int is_single_operator(char c) {
    char single_operators[] = "+-*/%&|^!~<>=";
    for (int i = 0; single_operators[i] != '\0'; i++) {
        if (c == single_operators[i]) {
            return 1;
        }
    }
    return 0;
}
int count_operators(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (is_single_operator(c)) {
            count++;
        }
    }
    return count;
}
int main() {
    const char *filename = "text.txt";
    FILE *file;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    int operator_count = count_operators(file);
    printf("Total number of single-character operators in %s: %d\n", filename, operator_count);
    fclose(file);
    return 0;
}