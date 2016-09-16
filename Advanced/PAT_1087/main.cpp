#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <queue>

using namespace std;
typedef struct
{
    int v;
    int cost;

}Edge;
int V, E;
string src;
map<string, int> m1;
map<int, string> m2;
vector< vector<Edge> > edge;
int happy[256];
void init()
{
    cin >> V >> E >> src;
    edge.resize(V + 1);
    m1[src] = 1;
    m2[1] = src;
    happy[1] = 0;
    for(int i = 2; i <= V; i++)
    {
        string name;
        cin >> name >> happy[i];
        m1[name] = i;
        m2[i] = name;
    }
    while(E--)
    {
        string s, d;
        int cost;
        cin >> s >> d >> cost;
        Edge e;
        e.cost = cost;
        e.v = m1[d];
        edge[m1[s]].push_back(e);
        e.v = m1[s];
        edge[m1[d]].push_back(e);
    }
}
int dist[256];
int hp[256];
int num[256];
int vst[256];
int pre[256];
void spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(hp, -1, sizeof(hp));
    memset(vst, 0, sizeof(vst));
    memset(pre, -1, sizeof(pre));
    memset(num, -1, sizeof(num));

    dist[1] = 0;
    hp[1] = 0;
    num[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        vst[v] = 0;
        for(int i = 0; i < edge[v].size(); i++)
        {
            int x = edge[v][i].v;
            int push = 0;
            if(dist[v] + edge[v][i].cost < dist[x])
                push = 1;
            else if(dist[v] + edge[v][i].cost == dist[x] && hp[v] + happy[x] > hp[x])
                push = 1;
            else if(dist[v] + edge[v][i].cost == dist[x] && hp[v] + happy[x] == hp[x] && num[v] + 1 < num[x])
                push = 1;
            if(push)
            {
                hp[x] = hp[v] + happy[x];
                num[x] = num[v] + 1;
                pre[x] = v;
                if(!vst[x])
                {
                    vst[x] = 1;
                    q.push(x);
                }
            }

        }
    }
}
int cnt = 0;
void dfs(int v)
{
    if(v == m1["ROM"])
    {
        cnt++;
    }
    if(vst[v])
        return;

    vst[v] = 1;
    for(int i = 0; i < edge[v].size(); i++)
    {
        int x = edge[v][i].v;
        if(dist[v] + edge[v][i].cost == dist[x])
            dfs(x);
    }
    vst[v] = 0;
}
int main()
{
    init();
    spfa();
    memset(vst, 0, sizeof(vst));
    dfs(1);
    string path[256];
    int k = 0;
    int p = m1["ROM"];

    while(p != -1)
    {
        path[k++] = m2[p];
        p = pre[p];
    }
    int d = m1["ROM"];
    cout << cnt << " " << dist[d] << " " << hp[d] << " " << hp[d] / num[d] << endl;
    while(k--)
    {
        cout << path[k] << (k == 0 ? "\n" : "->");
    }
    return 0;
}
