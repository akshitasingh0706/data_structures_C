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
    printf("The Elements are \n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    // first, check if there is any free space available at all
    // by check if the size of the array is greater than its legnth
    if (arr->length < arr-> size)
        // then add an element at A[length]
        // and also increase the the length by 1: length++
        // these both happen in one command itself
        arr->A[arr->length++] = x;
}

int main(int argc, const char * argv[]) {
    
    
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    
    Append(&arr, 70);    
    Display(arr);
    
    return 0;
}
