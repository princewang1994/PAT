#include <stdio.h>
#include <string.h>

using namespace std;

const int MAX = 100005;

int cnt[MAX];
int N;
int stack[MAX];
int len = -1;

void init()
{
    memset(cnt, 0, sizeof(cnt));
}
void add(int pos, int delt)
{
    while(pos <= MAX)
    {
        cnt[pos] += delt;
        pos += pos&-pos;
    }
}
int sum(int i)
{
    int s = 0;
    while(i)
    {
        s += cnt[i];
        i -= i&-i;
    }
    return s;
}
void push()
{
    int key;
    scanf("%d", &key);
    stack[++len] = key;
    add(key, 1);
}
void pop()
{
    if(len == -1)
    {
        printf("Invalid\n");
        return;
    }
    int key = stack[len];
    len--;
    add(key, -1);
    printf("%d\n", key);
}
int binsearch(int s)
{
    int l = 0, r = MAX - 1;
    int mid;
    while(l <= r)
    {
        mid = ((l + r) / 2);
        int k = sum(mid);
        if(s <= k)
        {
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}
void mid()
{
    if(len == -1)
    {
        printf("Invalid\n");
        return;
    }
    printf("%d\n", binsearch((len + 2) / 2));
}
int main()
{
    scanf("%d", &N);
    init();
    while(N--)
    {
        char cmd[16];
        scanf("%s", cmd);
        switch(cmd[1])
        {
        case 'u':push();break;
        case 'o':pop();break;
        case 'e':mid();break;
        }
    }

    return 0;
}
