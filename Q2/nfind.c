#include <stdio.h>
#include <string.h>

int nfind( char *text,  char *pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int patLast = pattern_len - 1;

    for (int i = 0; i <= text_len - pattern_len; ++i) {
        int j;
        if(text[i+pattern_len-1]!=pattern[patLast])
            continue;
        for (j = 0; j < pattern_len; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == pattern_len) {
            return i; 
        }
    }

    return -1; 
}

int main() {

    char text[1000];
    printf("Enter a string: ");
    scanf("%s", text);

    char pattern[1000];
    printf("\nEnter a pattern to check if its present in the entered string: ");
    scanf("%s", pattern);
 

    int index = nfind(text, pattern);

    if (index != -1) {
        printf("Pattern found at index: %d\n", index);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}

