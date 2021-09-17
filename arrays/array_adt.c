//
//  main.c
//  ArrayADT
//
//  Created by AKSHITA SINGH on 8/9/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
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

int main(int argc, const char * argv[]) {
    struct Array arr;
    
    // size (of memory in heap)
    printf("Enter the size of an array ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    
    // length (number of elements within the array, which can be < size)
    arr.length = 0;
    int n;
    printf("Enter the number of elements ");
    scanf("%d", &n);
    printf("Print all elements\n");
    
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.length = n;
    
    Display(arr);
    
    return 0;
}
