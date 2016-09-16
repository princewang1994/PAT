#include <iostream>
#include <string.h>

using namespace std;

int f[10005];
int vst[10005];
int cnt;
void init()
{
    for(int i = 0; i < 10005; i++)
    {
        f[i] = i;
    }
}
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
int cntTree()
{
    int tree = 0;
    for(int i = 0; i < 10005; i++)
    {
        if(vst[i] && f[i] == i)
            tree++;
    }
    return tree;
}
int main()
{
    memset(vst, 0, sizeof(vst));
    init();
    int N;
    cin >> N;
    while(N--)
    {
        int n;
        cin >> n;
        int first;
        cin >> first;
        if(!vst[first])
        {
            vst[first] = 1;
            cnt++;
        }
        n--;
        while(n--)
        {
            int bird;
            cin >> bird;
            if(!vst[bird])
            {
                vst[bird] = 1;
                cnt++;
            }
            merge(first, bird);
        }
    }
    cout << cntTree() << " " << cnt << endl;
    int K;
    cin >> K;
    while(K--)
    {
        int a, b;
        cin >> a >> b;
        cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    }
    return 0;
}
