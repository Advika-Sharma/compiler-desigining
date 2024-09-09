#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define NUM_KEYWORDS 32
const char* keywords[NUM_KEYWORDS] = {
    "auto", "default", "signed", "enum",
    "extern", "for", "register", "if",
    "else", "int", "while", "do",
    "break", "continue", "double", "float",
    "return", "char", "case", "const",
    "sizeof", "long", "short", "typedef",
    "switch", "unsigned", "void", "static",
    "struct", "goto", "union", "volatile"
};
bool isKeyword(const char* str) {
    for (int i = 0; i < NUM_KEYWORDS; ++i) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
int main() {
    char input[50];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isKeyword(input)) {
        printf("Yes, it is a C keyword\n");
    } else {
        printf("No, it is not a C keyword\n");
    }
    return 0;
}