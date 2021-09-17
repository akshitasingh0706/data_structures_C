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

struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int i =0;
    int j =0;
    int k =0;
    
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length)
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    for(;i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(;j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
//    while (i < arr1->length)
//        arr3->A[k++] = arr1->A[i++];
//    while (j < arr2->length)
//        arr3->A[k++] = arr2->A[j++];
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->length + arr2->length;
    
    return arr3;
}

int main(int argc, const char * argv[])
{
    struct Array arr1 = {{10, 20, 30, 40, 50}, 10, 5};
    struct Array arr2 = {{15, 25, 35, 45, 100}, 10, 5};
    struct Array *arr3;
    arr3 = merge(&arr1, &arr2);
    Display(*arr3);
    
    return 0;
}

