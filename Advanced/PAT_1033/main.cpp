#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <vector>
const int INF = 0x3f3f3f3f;

using namespace std;
typedef struct
{
    double cost;
    double dist;
} Node;

double dp[30005];
Node node[30005];
int vst[60005];
vector<double> pass;
double pay = 0;

double  dist, tank, unit;
int N;

int cmp(Node n1, Node n2)
{
    return n1.cost < n2.cost;
}

int gred()
{
    double kg = tank * unit;

    for(int i = 0; i < N; i++)
    {
        Node nd = node[i];

        int index = 0;

        for(; abs(pass[index] - nd.dist) > 0.0001; index++);
        int begin = index;

        while( kg >= (pass[index + 1] - pass[begin]) && index < (pass.size() - 1))
        {
            if(!vst[index])
            {
                vst[index] = 1;
                pay +=  (pass[index + 1] - pass[index]) / unit * nd.cost;
            }
            index++;
        }
    }

    int i = 0;
    while(vst[i])
    {
        i++;
    }
    return i;
}

int main()
{
    cin >> tank >> dist >> unit >> N;

    int k = 0;
    int n = N;

    while(n--)
    {
        cin >> node[k].cost >> node[k].dist;
        pass.push_back(node[k].dist);
        if(node[k].dist + unit * tank <= dist)
        {
            pass.push_back(node[k].dist + unit * tank);
        }
        k ++;
    }
    pass.push_back(dist);

    sort(node, node + N, cmp);
    sort(pass.begin(), pass.end());

    memset(vst, 0, sizeof(vst));

    int far = gred();
    if(far != pass.size() - 1)
        printf("The maximum travel distance = %.2f", pass[far]);
    else
        printf("%.2f\n", pay);
    return 0;
}
