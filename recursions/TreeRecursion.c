//
//  main.c
//  TreeRecursion
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

void fun(int n)
{
    if (n > 5)
    {
        printf("%d\n", n);
        fun(n-1);
        fun(n-1);
    }
}

int main(int argc, const char * argv[]) {
    fun(9);
    return 0;
}
