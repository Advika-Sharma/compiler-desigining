#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 10
#define MAX_FIRST 10

char productions[MAX_PRODUCTIONS][10];
char first[MAX_PRODUCTIONS][MAX_FIRST];
int productionCount = 0;

void calculateFIRST(char nonTerminal);

int main() {
    printf("How many productions? (max %d): ", MAX_PRODUCTIONS);
    scanf("%d", &productionCount);

    printf("Enter %d productions (format A->B):\n", productionCount);
    for (int i = 0; i < productionCount; i++) {
        printf("Production %d: ", i + 1);
        scanf("%s", productions[i]);
    }

    char nonTerminal;
    while (1) {
        printf("Enter a non-terminal (or '0' to exit): ");
        scanf(" %c", &nonTerminal);
        if (nonTerminal == '0') break;
        calculateFIRST(nonTerminal);
        printf("FIRST(%c) = { ", nonTerminal);
        for (int i = 0; first[nonTerminal - 'A'][i] != '\0'; i++)
            printf("%c ", first[nonTerminal - 'A'][i]);
        printf("}\n");
    }
    return 0;
}

void calculateFIRST(char nonTerminal) {
    int index = nonTerminal - 'A';
    first[index][0] = '\0'; // Reset FIRST set

    for (int i = 0; i < productionCount; i++) {
        if (productions[i][0] == nonTerminal) {
            char *prod = productions[i] + 3; // Skip "A->"
            while (*prod) {
                if (islower(*prod)) {
                    strncat(first[index], prod, 1);
                    break;
                } else if (isupper(*prod)) {
                    calculateFIRST(*prod);
                    strncat(first[index], first[*prod - 'A'], MAX_FIRST);
                    break;
                } else if (*prod == '$') {
                    strncat(first[index], "$", 1);
                    break;
                }
                prod++;
            }
        }
    }
}
