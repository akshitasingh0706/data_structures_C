//
//  main.c
//  TailHead
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

void fun(int n)
{
    if (n > 0)
    {
        fun(n-1);
        printf("%d ", n);
//        fun(n-1);
    }
}

int main(int argc, const char * argv[])
{
    int x = 3;
    fun(x);
    return 0;
}

