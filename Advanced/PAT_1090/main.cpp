#include <vector>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cmath>
using namespace std;
int maxLevel = 0;
int cnt = 0;
vector<int> retail[100005];
int main()
{
    int N;
    double P, r;
    cin >> N >> P >> r;
    //scanf("%d %f %f", &N, &P, &r);
    queue<int> q, level;
    for(int i = 0; i < N; i++)
    {
        int father;
        scanf("%d", &father);
        if(father != -1)
        {
            retail[father].push_back(i);
        }
        else
        {
            q.push(i);
            level.push(0);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        int l = level.front();
        q.pop(); level.pop();

        if(l > maxLevel)
        {
            cnt = 0;
            maxLevel = l;
        }
        if(l == maxLevel)
        {
            cnt++;
        }

        for(int i = 0; i < retail[v].size(); i++)
        {
            q.push(retail[v][i]);
            level.push(l + 1);
        }
    }
    printf("%.2f %d", P * pow(1 + r / 100, maxLevel), cnt);
    return 0;
}
