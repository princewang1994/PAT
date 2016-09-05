#include <stdio.h>
#include <cmath>
using namespace std;

long num[128];
long den[128];
long long gcd(long long x, long long y)
{
    if(x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
    return x * y / gcd(x, y);
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%ld/%ld", &num[i], &den[i]);
    }

    long long lc = den[0];
    for(int i = 1; i < N; i++)
    {
        lc = lcm(lc, den[i]);
    }
    long long sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += lc / den[i] * num[i];
    }

    int sign = sum * lc > 0 ? 1 : -1;
    sum =abs(sum);
    long long Int = sum / lc;
    sum %= lc;

    long long d = gcd(sum, lc);
    sum /= d;
    lc /= d;
    if(Int != 0)
    {
        printf("%lld ", Int);
        if(sum != 0)
            printf("%lld/%lld\n", sign * sum, lc);
    }
    else
    {
        if(sum != 0)
            printf("%lld/%lld\n", sign * sum, lc);
        else
            printf("0\n");
    }

    return 0;
}
