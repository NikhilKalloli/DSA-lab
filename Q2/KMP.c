#include <stdio.h>
#include <string.h>

int patternMatch(char *text, char *pattern, int *failure) {
    int i = 0, j = 0;
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    while (i < textLength && j < patternLength) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else if (j == 0) {
            i++;
        } else {
            j = failure[j - 1] + 1;
        }
    }

    if(j==patternLength) return i-patternLength;
    return -1;
}

void computeFailure(char *pattern, int *failure) {
    int i, j;
    int patternLength = strlen(pattern);
    failure[0] = -1;

    for (j = 1; j < patternLength; j++) {
        i = failure[j - 1];
        if ((pattern[j] != pattern[i + 1]) && (i >= 0)) {
            i = failure[i];
        }
        if (pattern[j] == pattern[i + 1]) {
            failure[j] = i + 1;
        } else {
            failure[j] = -1;
        }
    }
}

int main() {
    char text[1000];
    printf("Enter a string: ");
    scanf("%s", text);

    char pattern[1000];
    printf("Enter a pattern to check if it's present in the entered string: ");
    scanf("%s", pattern);

    int failure[1000];
    computeFailure(pattern, failure);

    int matchIndex = patternMatch(text, pattern, failure);

    if (matchIndex != -1) {
        printf("Pattern found at index %d\n", matchIndex);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}
