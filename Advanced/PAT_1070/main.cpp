#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct
{
    double weight;
    double p;
}Mooncake;
Mooncake cake[1024];
int cmp(Mooncake a, Mooncake b)
{
    return a.p / a.weight > b.p / b.weight;
}
int main()
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> cake[i].weight;
    }
    for(int i = 0; i < N; i++)
    {
        cin >> cake[i].p;
    }
    sort(cake, cake + N, cmp);
    int m = 0;
    int i = 0;
    double p = 0;
    while(i < N && m + cake[i].weight < M)
    {
        m += cake[i].weight;
        p += cake[i].p;
        i++;
    }
    if(m == M || i == N)
    {
        printf("%.2f", p);
    }
    else{
        printf("%.2f", p + double(M - m) / cake[i].weight * cake[i].p);
    }

    return 0;
}
