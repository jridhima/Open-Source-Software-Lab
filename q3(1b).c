#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_LENGTH];
    int freq[MAX_WORDS] = {0};
    int count = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    for (int i = 0; paragraph[i]; i++) {
        paragraph[i] = tolower(paragraph[i]);
    }

    char *token = strtok(paragraph, " ,.-!?;\n\t");
    while (token != NULL) {
        int found = -1;
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], token) == 0) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            freq[found]++;
        } else {
            strcpy(words[count], token);
            freq[count] = 1;
            count++;
        }

        token = strtok(NULL, " ,.-!?;\n\t");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
