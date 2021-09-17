//
//  main.c
//  NestedRecursion
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

int fun(int n)
{
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n+11));
}

int main(int argc, const char * argv[]) {
    int r;
    r = fun(98);
    printf("%d\n", r);
    return 0;
}
