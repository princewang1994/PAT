#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
map<long, long> color;
long cnt = 0;
long Max = -1;
int main()
{
    int M, N;
    scanf("%d%d", &M, &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            long clr;
            scanf("%ld", &clr);
            cnt = ++color[clr];
            if( cnt > M * N / 2)
            {
                printf("%ld", clr);
                return 0;
            }
        }
    }
    return 0;
}
