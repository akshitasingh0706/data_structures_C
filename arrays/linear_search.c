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

void Swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *arr, int x)
{
    int index;
    for (index = 0; index < arr->length; index++)
        if (x == arr->A[index])
            return index;
    return -1;
}

/* improve Linear Search by Transposition
   (swap the element where found with the previous one)
   reduces time complexity by a little */

int linearSearch2(struct Array *arr2, int x)
{
    int index;
    for (index = 0; index < arr2->length; index++)
        if (x == arr2->A[index])
            Swap(&arr2->A[index], &arr2->A[index-1]);
            return index;
    return -1;
}

/* improve Linear Search by Move To Head
   (swap the element where found with the first one)
   reduces time complexity by a lot */

int linearSearch3(struct Array *arr3, int x)
{
    int index;
    for (index = 0; index < arr3->length; index++)
        if (x == arr3->A[index])
            Swap(&arr3->A[index], &arr3->A[0]);
            return index;
    return -1;
}

int main(int argc, const char * argv[])
{
    
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    printf("The key is at: %d\n", linearSearch(&arr, 30));
    Display(arr);
    
    struct Array arr2 = {{10, 20, 30, 40, 50}, 10, 5};
    printf("The key is at: %d\n", linearSearch2(&arr2, 30));
    Display(arr2);
    
    struct Array arr3 = {{10, 20, 30, 40, 50}, 10, 5};
    printf("The key is at: %d\n", linearSearch3(&arr3, 30));
    Display(arr3);
    
    return 0;
}
