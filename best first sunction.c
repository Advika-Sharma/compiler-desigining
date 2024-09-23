#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void FIRST(char);
int count, n = 0;
char prodn[10][10], first[10];
bool visited[10];

void main() {
    int i, choice;
    char c, ch;

    printf("How many productions? : ");
    scanf("%d", &count);

    printf("Enter %d productions (epsilon = $):\n", count);
    for (i = 0; i < count; i++) {
        scanf("%s%c", prodn[i], &ch);
        visited[i] = false;
    }

    do {
        n = 0;
        printf("Element: ");
        scanf(" %c", &c);

        FIRST(c);

        printf("\nFIRST(%c) = { ", c);
        for (i = 0; i < n; i++) {
            printf("%c", first[i]);
            if (i < n - 1) {
                printf(", ");
            }
        }
        printf("}\n");

        printf("Press 1 to continue: ");
        scanf("%d%c", &choice, &ch);
    } while (choice == 1);
}

void FIRST(char c) {
    int j;

    if (!isupper(c)) {
        if (n == 0 || first[n - 1] != c) {
            first[n++] = c;
        }
    }

    for (j = 0; j < count; j++) {
        if (prodn[j][0] == c) {
            if (visited[j]) continue;
            visited[j] = true;

            if (prodn[j][2] == '$') {
                if (n == 0 || first[n - 1] != '$') {
                    first[n++] = '$';
                }
            } else {
                int k = 2; // Start after the non-terminal and '='
                while (prodn[j][k] != '\0') {
                    if (islower(prodn[j][k])) {
                        if (n == 0 || first[n - 1] != prodn[j][k]) {
                            first[n++] = prodn[j][k];
                        }
                        break;
                    } else {
                        FIRST(prodn[j][k]);
                        if (n > 0) break; // Stop if we've found a terminal
                    }
                    k++;
                }
            }
        }
    }
}
