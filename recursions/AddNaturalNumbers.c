//
//  main.c
//  AddNaturalNums
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

// recursive

int fun(int n)
{
    if (n > 0)
    {
        return fun(n-1) + n;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    int r;
    r = fun(10);
    printf("%d\n", r);
    return 0;
}



// normal
//
//int main(int argc, const char * argv[])
//{
//    int sum = 0;
//    int n = 1;
//    while (n < 11)
//    {
//        sum += n;
//        n++;
//    }
//    printf("%d\n", sum);
//
//    return 0;
//}
