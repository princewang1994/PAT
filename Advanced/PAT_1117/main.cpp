#include <stdio.h>
#include <algorithm>
using namespace std;

int mile[100005];
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &mile[i]);
    }
    sort(mile, mile + N);
    int ptr = N - 1;
    for(int i = N; i >= 0; i--)
    {
        while(mile[ptr] > i)ptr--;
        if(N - 1 - ptr >= i)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
