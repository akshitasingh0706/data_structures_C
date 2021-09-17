//
//  main.c
//  Insert
//
//  Created by AKSHITA SINGH on 8/9/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

// we create a generic array structure with the following elements
// an array with a certain size, the size, and the length of the array
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

// now we create a void function that takes in the following arguments
// pointer to the struct Array
// index where we want the insert
// and the value we want to insert
void Insert(struct Array *arr, int index, int x)
{
    // we first check if the index is a value, for it cannot be
    // either less than 0 or more than the current length of the arr
    if (index >= 0 && index <= arr->length)
        // iterate from the new length (which is old length + 1)
        // down to the index value right after the index
        for (int i = arr->length; i > index; i--)
            /* we shift all values starting from the value
             where we need to insert to the right, such that
             we create space for the new value at the index */
            arr->A[i] = arr->A[i-1];
        
        // once we have created space
        // we insert the desired value at the desired index
        arr->A[index] = x;
        /* finally, because the length of the array
         would increase after insertion we reflect that by
         increasing the length paramter of the object arr */
        arr->length++;
}


int main(int argc, const char * argv[]) {
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    
    /* notice that when we call the function Insert
     for the first paramter
    we input an array address, not the array */
    Insert(&arr, 2, 24);
    Display(arr);
    return 0;
}
