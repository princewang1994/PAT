#include <stdio.h>
using namespace std;
int sum[100005];
int a[100005];
int b[100005];
int len = 0;
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    sum[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        scanf("%d", &n);
        sum[i] = sum[i - 1] + n;
    }

    int i = 1;
    int Min = 0x3f3f3f3f;

    for(int j = 1; j <= N; j++)
    {
        while(i <= j)
        {
            int s = sum[j] - sum[i - 1];
            if(s < M)
            {
                break;
            }

            if(s - M < Min)
            {
                Min = s - M;
                len = 0;
                a[len] = i;
                b[len++] = j;
            }
            else if(s - M == Min){
                a[len] = i;
                b[len++] = j;
            }
            i++;
        }

    }
    for(int i = 0; i < len; i++)
    {
        printf("%d-%d\n", a[i], b[i]);
    }
    return 0;
}
