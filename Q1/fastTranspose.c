#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

void fastTranspose(Term a[], Term b[]) {
    int numTerms = a[0].value;
    int numCols = a[0].col;
    int arr1[numCols];
    int arr2[numCols];

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    if (numTerms > 0) {
        for (int i = 0; i < numCols; i++) {
            arr1[i] = 0;
        }

        for (int i = 1; i <= numTerms; i++) {
            arr1[a[i].col]++;
        }

        arr2[0] = 1;

        for (int i = 1; i < numCols; i++) {
            arr2[i] = arr2[i - 1] + arr1[i - 1];
        }

        for (int i = 1; i <= numTerms; i++) {
            int currentCol = a[i].col;
            int newPosition = arr2[currentCol]++;
            
            b[newPosition].row = a[i].col;
            b[newPosition].col = a[i].row;
            b[newPosition].value = a[i].value;
        }
    }
}

void displayMatrix(Term a[]) {
    int numTerms = a[0].value;

    for (int i = 0; i <= numTerms; i++) {
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
    }
}

int main() {
    Term a[MAX_TERMS], b[MAX_TERMS];

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &a[0].row);

    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &a[0].col);

    printf("Enter the number of non-zero elements in the matrix: ");
    scanf("%d", &a[0].value);

    printf("Enter the elements of the matrix (row, column, value):\n");
    for (int i = 1; i <= a[0].value; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    printf("Original sparse Matrix:\n");
    displayMatrix(a);

    fastTranspose(a, b);

    printf("Transposed sparse Matrix:\n");
    displayMatrix(b);

    return 0;
}
