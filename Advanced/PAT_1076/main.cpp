#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector< vector<int> > edge;
int N, L;
void init()
{
    cin >> N >> L;
    edge.resize(N + 1);
    for(int i = 1; i <= N; i++)
    {
        int n;
        cin >> n;
        while(n--)
        {
            int a;
            cin >> a;
            edge[a].push_back(i);
        }
    }
}
int vst[1024];
int bfs(int v)
{
    memset(vst, 0, sizeof(vst));
    queue<int> q;
    queue<int> l;
    q.push(v);
    l.push(0);
    vst[v] = 1;
    int cnt = 0;
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        int level = l.front(); l.pop();

        cnt++;
        for(int i = 0; i < edge[x].size(); i++)
        {
            if(level == L) break;
            int p = edge[x][i];
            if(!vst[p])
            {
                vst[p] = 1;
                q.push(p);
                l.push(level + 1);
            }
        }
    }
    return cnt;

}
int main()
{
    init();
    int k;
    cin >> k;
    while(k--)
    {
        int n;
        cin >> n;
        cout << bfs(n) - 1<< endl;
    }

    return 0;
}
