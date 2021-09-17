//
//  main.c
//  2DArrays
//
//  Created by AKSHITA SINGH on 8/9/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    // Method 1: ALL Stack (rows and columns created in stack)
    int A[3][4] = {{1,3,5,7},{2,4,6,8},{4,9,5,0}};
    
    // Method 2: Some Stack, Some Heap (rows in stack, columns in heap)
    int *B[3]; // in stack (for rows)
    B[0] = (int *)malloc(4*sizeof(int)); // 1st row element points to an array with 4 elements in heap
    B[1] = (int *)malloc(4*sizeof(int)); // 2nd row element points to an array with 4 elements in heap
    B[2] = (int *)malloc(4*sizeof(int)); // 3rd row element points to an array with 4 elements in heap
    
    // Method 3: ALL Heap (rows and columns in heap)
    int **C;
    C = (int **)malloc(3*sizeof(int *)); // Array of integer pointers
    C[0] = (int *)malloc(4*sizeof(int)); // 1st element (an int pointer) points an array with 4 elements
    C[1] = (int *)malloc(4*sizeof(int)); // 2nd element (an int pointer) points an array with 4 elements
    C[2] = (int *)malloc(4*sizeof(int)); // 3rd element (an int pointer) points an array with 4 elements

    // See how it works
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d  ", A[i][j]);
        printf("\n");
    }
    
    // unitialized so garbage values shall be printed
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d  ", B[i][j]);
        printf("\n");
    }
    
    return 0;
}
