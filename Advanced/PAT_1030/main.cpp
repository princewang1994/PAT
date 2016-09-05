#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;
typedef struct
{
    int v;
    int dist;
    int cost;
}Edge;

vector< vector<Edge> > edge;

int V, E, S, D;

void init()
{
    cin >> V >> E >> S >> D;
    edge.resize(V);
    while(E--)
    {
        int start, end, dist, cost;
        cin >> start >> end >> dist >> cost;
        Edge e;
        e.dist = dist;
        e.cost = cost;

        e.v = end;
        edge[start].push_back(e);
        e.v = start;
        edge[end].push_back(e);
    }
}
int pre[512];
int vst[512];
int dist[512];
int cost[512];

void spfa(int v)
{
    memset(vst, 0, sizeof(vst));
    memset(dist, 0x3f, sizeof(vst));
    memset(pre, -1, sizeof(pre));
    memset(cost, 0x3f, sizeof(cost));

    queue<int> q;
    dist[v] = 0;
    cost[v] = 0;
    q.push(v);  vst[v] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop(); vst[x] = 0;
        for(int i = 0; i < edge[x].size(); i++)
        {
            int cur = edge[x][i].v;
            if(dist[x] + edge[x][i].dist < dist[cur])
            {
                dist[cur] = dist[x] + edge[x][i].dist;
                cost[cur] = cost[x] + edge[x][i].cost;
                pre[cur] = x;
                if(!vst[cur])
                {
                    q.push(cur); vst[cur] = 1;
                }
            }
            else if(dist[x] + edge[x][i].dist == dist[cur] && cost[x] + edge[x][i].cost < cost[cur])
            {
                dist[cur] = dist[x] + edge[x][i].dist;
                cost[cur] = cost[x] + edge[x][i].cost;
                pre[cur] = x;
                if(!vst[cur])
                {
                    q.push(cur); vst[cur] = 1;
                }
            }
        }
    }
}
int main()
{
    init();
    spfa(S);

    int v = D;
    stack<int> path;
    while(v != -1)
    {
        path.push(v);
        v = pre[v];
    }
    while(!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << dist[D] << " ";
    cout << cost[D] << endl;
    return 0;
}
