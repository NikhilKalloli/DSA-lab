#include<stdio.h>

#define MAX_TERMS 100

typedef struct
{
    int row;
    int col;
    int value;
} Term;

void transpose(Term a[], Term b[]){
    int currentb;
    int numTerms = a[0].value;
    int numCols = a[0].col;

    b[0].col = a[0].col;
    b[0].row = a[0].row;
    b[0].value = a[0].value;

    if(numTerms>0){
        currentb=1;
        for(int i =0; i<numCols; i++){
            for(int j=1; j<=numTerms;j++){
                if(a[j].col==i){
                    b[currentb].row= a[j].col;
                    b[currentb].col= a[j].row;
                    b[currentb].value= a[j].value;
                    currentb++;
                }
            }

        }
    }


}

void fastTranspose(Term a[], Term b[]){
    int numTerms = a[0].value;
    int numCols = a[0].col;

    int colTerms[numCols];
    int startingPos[numCols];

    b[0].row = a[0].col;
    b[0].col  = a[0].row;
    b[0].value = a[0].value;

    if(numTerms>0){
        for(int i=0;i<numCols;i++){
            colTerms[i]=0;
        }

        for(int i=1;i<=numTerms;i++){
            colTerms[a[i].col]++;
        }

        startingPos[0]=1;

        for(int i =1; i<numCols; i++){
            startingPos[i] = startingPos[i-1] + colTerms[i-1];
        }

        for(int i=1;i<=numTerms;i++){
            int currentCol = a[i].col;
            int newPosition = startingPos[currentCol]++;

            b[newPosition].row = a[i].col;
            b[newPosition].col = a[i].row;
            b[newPosition].value = a[i].value;
        }


    }

}




void display(Term a[]){
     for(int i =1; i<=a[0].value;i++){
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
    }
}

int main(){

    Term a[MAX_TERMS], b[MAX_TERMS];

    printf("Enter total rows: ");
    scanf("%d", &a[0].row);

    printf("Enter total cols: ");
    scanf("%d", &a[0].col);

    printf("Enter total non zero elements: ");
    scanf("%d", &a[0].value);

    printf("Enter (row,col,value)\n");
    for(int i =1; i<=a[0].value;i++){
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    printf("Original Matrix\n");
    display(a);
    // transpose(a ,b);
    fastTranspose(a,b);
    printf("After Transpose\n");
    display(b);


    return 0;
}