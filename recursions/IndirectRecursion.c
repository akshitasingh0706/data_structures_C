//
//  main.c
//  IndirectRecursion
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

//define funB before it is called
void funB(int n);

void funA(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        printf("%d\n", n);
        funA(n/2);
    }
}



int main(int argc, const char * argv[]) {
    funA(20);
    return 0;
}
