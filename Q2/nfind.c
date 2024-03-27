#include <stdio.h>
#include <string.h>

int nfind(char *text, char *pattern)
{
    int m = strlen(text) - 1;
    int n = strlen(pattern) - 1;
    int start = 0;
    int end = n;

    int j = 0;
    for (int i = 0; end <= m; start++, end++)
    {
        if (text[end] == pattern[n])
        {
            for (i = start, j = 0; j <= n && text[i] == pattern[j]; i++, j++)
                ;
            if (j == n + 1)
                return start;
            return -1;
        }
    }
}

int main()
{

    char text[1000];
    printf("Enter a string: ");
    scanf("%s", text);

    char pattern[1000];
    printf("\nEnter a pattern to check if its present in the entered string: ");
    scanf("%s", pattern);

    int index = nfind(text, pattern);

    if (index != -1)
    {
        printf("Pattern found at index: %d\n", index);
    }
    else
    {
        printf("Pattern not found.\n");
    }

    return 0;
}
