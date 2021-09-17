//
//  main.c
//  TaylorSeries
//
//  Created by AKSHITA SINGH on 8/2/20.
//  Copyright © 2020 AKSHITA SINGH. All rights reserved.
//

#include <stdio.h>

double power(double m, int n)
{
    if (n == 0)
        return 1;
    
    if (n%2 == 0)
    {
        return power(m*m, n/2);
    }
    else
    {
        return m*power(m*m, (n-1)/2);
    }
    return 1;
}

int factorial(int n)
{
    if (n > 1)
    {
        return factorial(n-1)*n;
    }
    return 1;
}

double e(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return e(x, n-1) + power(x,n)/factorial(n);
    }
}

double e2(double x, int n)
{
    static double pow = 1, fact = 1;
    double tay;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        tay = e2(x, n-1);
    }
    pow *= x;
    fact *= n;
    return tay + pow/fact;
}


int main(int argc, const char * argv[]) {
    double r, s;
    r = e(3,10);
    s = e2(3,10);
    printf("%f\n", r);
    printf("%f\n", s);
    return 0;
}
