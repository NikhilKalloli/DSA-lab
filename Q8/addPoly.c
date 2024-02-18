#include <stdio.h>

typedef struct PolynomialAdd
{
    int coeff;
    int exp;
} Polynomial;


void read(Polynomial p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of the term %d: ", i + 1);
        scanf("%d", &p[i].coeff);

        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &p[i].exp);
    }
}

void display(Polynomial p[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        if(i==n-1){
            printf("%d(x^%d) ", p[i].coeff, p[i].exp);

        }
        else{
            printf("%d(x^%d) + ", p[i].coeff, p[i].exp);
        }
    }
    printf("\n");
}

int add(Polynomial p1[] , int n1 , Polynomial p2[], int n2, Polynomial p3[] , int n3){
    int i =0 , j =0, k =0;
    while(i<n1 && j<n2){
        if(p1[i].exp>p2[j].exp){
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        }
        else if(p1[i].exp<p2[j].exp){
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
        else if(p1[i].exp==p2[j].exp){
            p3[k].coeff = p1[i].coeff + p2[j].coeff ;
            p3[k].exp = p2[j].exp;
            i++;
            j++;
            k++;
        }

    }

    while(i<n1){
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }

    while (j < n2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }
    return k;
}


int main(){
    int n1 , n2 , n3;
    
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n1);

    Polynomial p1[n1];
    read(p1, n1);
    display(p1, n1);

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n2);

    Polynomial p2[n2];
    read(p2, n2);
    display(p2, n2);

    n3 = n1 + n2;
    Polynomial p3[n3];

    int k = add(p1, n1, p2, n2, p3, n3);
    printf("Final polynomial:\n");
    display(p3, k);

    return 0;
}


