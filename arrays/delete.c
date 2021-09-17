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

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
    
        arr->A[index] = x;
        arr->length++;
        
}

void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index <= arr->length)
        /* lay particular emphasis on how you index
         Insert went from the length of the arry down to the index
         Delete goes from the index to the length of the array
         Practice with an array and see why*/
        for (int i =  index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
}


int main(int argc, const char * argv[])
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    Delete(&arr, 2);
    Display(arr);
    
    return 0;
}
