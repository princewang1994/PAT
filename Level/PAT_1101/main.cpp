#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long num[100005];
long res[100005];
int flag[100005];

int cnt = 0;
int main()
{
    int N;
    scanf("%d", &N);
    memset(flag, 0, sizeof(flag));
    for(int i = 0; i < N; i++)
    {
        scanf("%ld", &num[i]);
    }

    long Max = -1;
    for(int i = 0; i < N; i++)
    {
        if(num[i] > Max)
            Max = num[i];
        else
            flag[i] = 1;
    }

    long Min = 0x7fffffff;
    for(int i = N - 1; i >= 0; i--)
    {
        if(num[i] <= Min)
        {
            Min = num[i];
            if(!flag[i]) res[cnt++] = num[i];
        }
    }

    sort(res, res + cnt);

    printf("%d\n", cnt);
    if(cnt > 0)
        printf("%ld", res[0]);
    for(int i = 1; i < cnt; i++)
        printf(" %ld", res[i]);
    printf("\n");
    return 0;
}
