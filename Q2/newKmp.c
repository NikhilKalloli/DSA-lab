#include<stdio.h>
#include<string.h>

void solve(char *pattern, int *arr, int m){
    arr[0]=0;
    int start =0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[start]){
            arr[i++]=++start;
        }
        else{
            if(start!=0){
                start=arr[start-1];
            }
            else{
                arr[i++]=0;
            }
        }
    }
}

void kmp(char *text, char *pattern){
    int m = strlen(pattern);
    int n = strlen(text);

    int arr[m];
    solve(pattern, arr, m);

    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]) {
            i++;
            j++;
        }
        if(j==m){
            printf("Pattern found at %d", i-j);
            j=arr[j-1];
        }
        else if(text[i]!=pattern[j]){
            if(j!=0) j=arr[j-1];
            else i++;
        }
    }
}



int main(){
    char text[1000];
    printf("Enter a string: ");
    scanf("%s", text);

    char pattern[1000];
    printf("Enter a pattern to check if it's present in the entered string: ");
    scanf("%s", pattern);

    kmp(text, pattern);

    return 0;
}