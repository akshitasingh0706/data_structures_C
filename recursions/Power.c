//
//  main.c
//  Power
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>


#include <stdio.h>

int power(int m, int n)
{
    
    if (n > 0)
    {
        return power(m, n-1)*m;
    }
    return 1;
}

int power2(int m, int n)
{
    if (n == 0)
        return 1;
    
    if (n%2 == 0)
    {
        return power2(m*m, n/2);
    }
    else
    {
        return m*power2(m*m, (n-1)/2);
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    
    int r,s;
    r = power(3, 5);
    s = power2(3, 5);
    printf("%d\n", r);
    printf("%d\n", s);
    return 0;
}
