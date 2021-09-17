//
//  main.c
//  Insert
//
//  Created by AKSHITA SINGH on 8/9/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display (struct Array arr)
{
    printf("The Elements are: ");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;
    
    B = (int *)malloc(arr->length*sizeof(int));
    for (i = arr->length-1, j = 0; i > 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse2(struct Array *arr)
{
    int i, j;
    
    for (i = 0, j = arr->length-1; i < j; i++, j--)
        Swap(&arr->A[i], &arr->A[j]);
}

void leftShift(struct Array *arr)
{
     for (int i = 0; i < arr->length; i++)
         arr->A[i] = arr->A[i+1];
}

void rotate(struct Array *arr)
{
    int temp = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i+1];
        arr->A[arr->length - 1] = temp;
}

int main(int argc, const char * argv[])
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    Reverse2(&arr);
//    leftShift(&arr);
//    rotate(&arr);
    Display(arr);
    
    return 0;
}

