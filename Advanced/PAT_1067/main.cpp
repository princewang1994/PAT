#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int num[100005];
int f[100005];
int find(int n)
{
    if(f[n] == n)
        return n;
    else return f[n] = find(f[n]);
}
int merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if(x != y)
    {
        f[y] = x;
        return 1;
    }
    else return 0;
}
void init()
{
    for(int i = 0; i < N; i++)
    {
        f[i] = i;
    }
}
int main()
{
    scanf("%d", &N);
    init();
    for(int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        num[n] = i;
        if(i == n)
        {
            merge(i - 1, i);
        }
    }
    int cnt = 0;
    while(1)
    {
        while(num[0] != 0)
        {
            merge(num[0] - 1, num[0]);
            swap(num[0], num[num[0]]);
            cnt++;
        }
        int i = find(N - 1);
        if(i == 0)
            break;
        else
        {
            swap(num[0], num[i]);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
