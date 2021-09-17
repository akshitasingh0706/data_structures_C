//
//  main.c
//  Factorial
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

int factorial(int n)
{
    if (n > 1)
    {
        return factorial(n-1)*n;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    
    int r;
    r = factorial(5);
    printf("%d\n", r);
    return 0;
}
