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

int find(char *text, char *pattern){
    int m = strlen(text)-1;
    int n = strlen(pattern)-1;
    int start = 0;
    int end = n;

    int j=0;
    for(int i=0;end<=m;start++, end++){
        if(text[end]==pattern[n]){
            for(i=start,j=0;j<=n && text[i]==pattern[j];i++,j++);
            if(j==n+1) return start;
            return -1;
        }
    }

}

int main() {

    char text[1000];
    printf("Enter a string: ");
    scanf("%s", text);

    char pattern[1000];
    printf("\nEnter a pattern to check if its present in the entered string: ");
    scanf("%s", pattern);
 

    int index = find(text, pattern);

    if (index != -1) {
        printf("Pattern found at index: %d\n", index);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}

