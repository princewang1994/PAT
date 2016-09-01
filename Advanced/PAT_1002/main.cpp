#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
using namespace std;

double A[1024];
int main()
{
    for(int i = 1024; i >= 0; i--)
    {
        A[i] = 0.0;
    }
    int k1, k2;

    scanf("%d", &k1);
    while(k1--)
    {
        int e;
        double a;
        cin >> e >> a;
        A[e] += a;
    }

    scanf("%d", &k2);
    int cnt = 0;
    while(k2--)
    {
        int e;
        double a;
        cin >> e >> a;
        A[e] += a;
    }

    for(int i = 1024; i >= 0; i--)
    {
        if(abs(A[i]) > 0.001)
        {
            cnt++;
        }
    }

    printf("%d", cnt);
    for(int i = 1024; i >= 0; i--)
    {
        if(abs(A[i]) > 0.001)
        {
            printf(" %d %.1f", i, A[i]);
        }
    }

    return 0;
}
