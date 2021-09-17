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

// Assume list already sorted

// iterative version of Binary Search
int iBinarySearch(struct Array arr, int key)
{
    int low, high, mid;
    low = 0;
    high = arr.length - 1;
    
    while (low <= high)
    {
        mid = (low + high)/2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// recursive version of Binary Search
int rBinarySearch(int arr[], int low, int high, int key)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high)/2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return rBinarySearch(arr, low, mid - 1, key);
        else
            return rBinarySearch(arr, mid + 1, high, key);
    }
    return -1;
}



int main(int argc, const char * argv[])
{
    struct Array arr = {{10, 20, 30, 40, 50}, 10, 5};
    printf("The key is at: %d\n", iBinarySearch(arr, 40));
    Display(arr);
    
    struct Array arr2 = {{10, 20, 30, 40, 50}, 10, 5};
    printf("The key is at: %d\n", rBinarySearch(arr2.A, 0, arr2.length, 20));
    Display(arr2);
    
    return 0;
}
