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

// assume first n natural numbers, sorted
int singleMissing1(struct Array *arr)
{
    int sum = 0;
    for (int i = 0; i < arr->length; i++)
        sum += arr->A[i];
    int miss = (arr->length + 1) * (arr->length + 2)/2 - sum;
    
    return miss;
}

// assume some consecutive natural numbers, sorted
int singleMissing2(struct Array *arr)
{
    int diff = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        if ((arr->A[i] - i) != diff)
            return diff + i;
    return -1;
}

// assume some consecutive natural numbers, sorted
void multMissing1(struct Array *arr)
{
    int diff = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        if ((arr->A[i] - i) != diff)
            while ((arr->A[i] - i) > diff)
            {
                printf("%d\n",diff + i);
                diff++;
            }
}

void multMissing2(struct Array *arr)
{
    int diff = arr->A[0];
    for (int i = 0; i < arr->length; i++)
        if ((arr->A[i] - i) != diff)
            while ((arr->A[i] - i) > diff)
            {
                printf("%d\n",diff + i);
                diff++;
            }
}

int main(int argc, const char * argv[])
{
    struct Array arr = {{6, 8, 9, 10, 12}, 10, 5};
//    printf("%d\n", singleMissing1(&arr));
//    printf("%d\n", singleMissing2(&arr));
    multMissing1(&arr);
    return 0;
}

