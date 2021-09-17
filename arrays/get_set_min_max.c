//
//  main.c
//  Insert
//
//  Created by AKSHITA SINGH on 8/9/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

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

int Get(struct Array *arr, int index)
{
    if (index > 0 && index <= arr->length)
        return arr->A[index];
    return -1;
}

int Set(struct Array *arr, int index, int key)
{
    if (index > 0 && index <= arr->length)
        return arr->A[index] = key;
    return -1;
}

int Max(struct Array *arr)
{
    int max = arr->A[0];
    
    for (int i = 0; i < arr->length; i++)
        if (arr->A[i] > max)
            max = arr->A[i];
        return max;
    return -1;
}

int Sum(struct Array *arr)
{
    int total = 0;
    
    for (int i = 0; i < arr->length; i++)
        total += arr->A[i];
    return total;
}


int main(int argc, const char * argv[])
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    printf("Get: %d\n", Get(&arr, 3));
    printf("Set: %d\n", Set(&arr, 3, 100));
    Display(arr);
    printf("Max: %d\n", Max(&arr));
    printf("Sum: %d\n", Sum(&arr));
    
    return 0;
}
