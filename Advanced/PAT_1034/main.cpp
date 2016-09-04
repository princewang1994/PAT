#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>

#define M 26 * 26 * 26
using namespace std;

typedef struct
{
    int v;
    int w;
} Edge;

typedef struct
{
    string name;
    int cnt;
}Res;

int cmp(Res r1, Res r2)
{
    return r1.name < r2.name;
}
vector< vector<Edge> > edge;
vector<Res> res;
map<int, string> i_s;
map<string, int> s_i;

int idx = 1;
int N, th;
int weight[M];

void init()
{
    cin >> N >> th;
    edge.resize(M);
    memset(weight, 0, sizeof(weight));

    while(N--)
    {
        int time;
        string begin, end;
        cin >> begin >> end >> time;
        if(s_i[begin] == 0)
        {
            i_s[idx] = begin;
            s_i[begin] = idx++;
        }
        if(s_i[end] == 0)
        {
            i_s[idx] = end;
            s_i[end] = idx++;
        }
        int u = s_i[begin];
        int v = s_i[end];

        Edge e;
        e.v = v;
        e.w = time;
        edge[u].push_back(e);
        weight[u] += time;
        weight[v] += time;
    }
}

int vst[M];
vector<int> sear;

int dfs(int v)
{
    if(vst[v])
        return 0;

    vst[v] = 1;

    sear.push_back(v);
    int sum = 0;
    for(int i = 0; i < edge[v].size(); i++)
    {
        sum += edge[v][i].w;
        sum += dfs(edge[v][i].v);
    }
    return sum;
}

int main()
{
    init();
    memset(vst, 0, sizeof(vst));
    for(int i = 1; i < idx; i++)
    {
        int t = dfs(i);

        if(t > th && sear.size() > 2)
        {
            int max = -1;
            int id = 0;
            for(int j = 0; j < sear.size(); j++)
            {
                if(weight[sear[j]] > max)
                {
                    max = weight[sear[j]];
                    id = sear[j];
                }
            }
            Res r;
            r.name = i_s[id];
            r.cnt = sear.size();
            res.push_back(r);
        }
        sear.clear();
    }

    sort(res.begin(), res.end(), cmp);
    cout << res.size() << endl;
    if(res.size() > 0)
    {
        for(int i = 0; i< res.size(); i++)
        {
            cout << res[i].name << " " << res[i].cnt << endl;
        }
    }
    return 0;
}
