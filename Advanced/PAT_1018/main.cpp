#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

int C, N, S, M;
struct edge
{
    int v;
    int cost;
};
vector<vector<edge> > head;
vector<int> bike;

int vst[512];
int pre[512];
int dist[512];
int need = 0;
int maxBike = -9999999;
int minDist = 0x3f3f3f3f;

void init()
{
    cin >> C >> N >> S >> M;

    memset(pre, -1, sizeof(pre));

    int n = N;
    bike.push_back(0);

    while(n--)
    {
        int b;
        cin >> b;
        bike.push_back(b);
    }

    head.resize(N + 1);
    while(M--)
    {
        int a, b, cost;
        cin >> a >> b >> cost;

        edge e;
        e.v = b;
        e.cost = cost;
        head[a].push_back(e);

        edge e2;
        e2.v = a;
        e2.cost = cost;
        head[b].push_back(e2);
    }
}
void spfa(int src)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vst, 0, sizeof(vst));

    queue<int> q;
    q.push(src);
    vst[src] = 1;
    dist[src] = 0;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        vst[v] = 0;
        for(int i = 0; i < head[v].size(); i++)
        {
            int near = head[v][i].v;

            if(dist[v] + head[v][i].cost < dist[near])
            {
                dist[near] = dist[v] + head[v][i].cost;
                if(!vst[near])
                {
                    q.push(near);
                    vst[near] = 1;
                }
            }
        }
    }
}

int take, back;
void dfs(int cur, int dest, int btake, int bback, int d)
{


    for(int i = 0; i < head[cur].size(); i++)
    {
        int v = head[cur][i].v;
        if(d + head[cur][i].cost == dist[v])
        {
            int diff = bike[v] - C / 2;

            if(diff < 0)
            {
                if(bback + diff >= 0)
                {
                    btake = 0;
                    bback = bback + diff;
                }
                else
                {
                    btake = bback + diff;
                    bback = 0;
                }
            }
            else
            {
                bback += diff;
            }

            if(v == dest)
            {
                take = btake;
                back = bback;
                return;
            }

            pre[v] = cur;
            dfs(v, dest, btake, bback, d + head[cur][i].cost);
        }
    }
}
int main()
{
    init();
    spfa(0);
    dfs(0, S, 0, 0, 0);

    cout << take << " ";

    int point = S;
    stack<int> s;

    while(point != -1)
    {
        s.push(point);
        point = pre[point];
    }

    while(!s.empty())
    {
        int v = s.top();
        s.pop();
        if(!s.empty())
        {
            cout << v << "->";
        }
        else{
            cout << v << " ";
        }
    }

    cout << back << endl;

    return 0;
}
