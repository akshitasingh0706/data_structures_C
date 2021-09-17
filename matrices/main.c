#include <stdio.h>

/* Diagonal Matrix */
struct Matrix1 {
    int A[10];
    int n;
};

void Set1(struct Matrix1 *m, int i, int j, int val)
{
     if(i == j) m->A[i-1] = val;
}

int Get1(struct Matrix1 m, int i, int j)
{
    if(i == j) return m.A[i-1];
    return 0;
}

/* Lower Triangular Matrx */
struct Matrix2 {
    int *A;
    int n;
};

void Set2(struct Matrix2 *m, int i, int j, int val)
{
     if(i >= j) m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]= val;
}

int Get2(struct Matrix1 m, int i, int j)
{
    if(i >= j) return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    return 0;
}

void Display(struct Matrix1 m)
{
    for(int i = 1; i <= m.n; i++)
    {
        for(int j = 1; j <= m.n; j++)
        {
            if(i==j) printf("%d", m.A[i-1]);
            printf("0 ");
        }
    }
}
