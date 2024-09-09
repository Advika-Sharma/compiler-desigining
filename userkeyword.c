#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_KEYWORDS 32
#define MAX_KEYWORD_LENGTH 10
#define MAX_LINE_LENGTH 100
const char *keywords[MAX_KEYWORDS] = {
    "auto", "default", "signed", "enum",
    "extern", "for", "register", "if",
    "else", "int", "while", "do",
    "break", "continue", "double", "float",
    "return", "char", "case", "const",
    "sizeof", "long", "short", "typedef",
    "switch", "unsigned", "void", "static",
    "struct", "goto", "union", "volatile"
};
bool isKeyword(const char *word) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcasecmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
int main() {
    FILE *file = fopen("TEST.txt", "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    char line[MAX_LINE_LENGTH];
    int keywordCount = 0;
    
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n");
        while (token) {
            if (isKeyword(token)) {
                keywordCount++;
            }
            token = strtok(NULL, " \t\n");
        }
    }
    fclose(file);
    printf("Total number of keywords: %d\n", keywordCount);
    return EXIT_SUCCESS;
}
