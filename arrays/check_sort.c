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

//void insertSort(struct Array *arr, int x)
//{
//    int i = arr->length - 1;
//
//    if (arr->length == arr->size)
//        return;
//    while (i >= 0 && arr->A[i] > x)
//        arr->A[i+1] = arr->A[i];
//        i--;
//    arr->A[i+1] = x;
//    arr->length++;
//}

int isSorted(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
        if (arr->A[i] > arr->A[i+1])
            return 0;
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;
    
    while (i < j)
    {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] > 0) j--;
        if (i < j) Swap (&arr->A[i], &arr->A[j]);
    }
}

int main(int argc, const char * argv[])
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
//    insertSort(&arr, 45);
    printf("Is sorted? %d\n", isSorted(&arr));
    Display(arr);
    
    struct Array arr2 = {{-10, 20, -30, 40, -50}, 10, 5};
    printf("Is sorted? %d\n", isSorted(&arr2));
    Rearrange(&arr2);
    Display(arr2);
    return 0;
}

