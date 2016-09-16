#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
typedef struct
{
    int addr;
    int data;
    int next;
}Mem;
int mem[100005];
int Next[100005];
vector<Mem> res;
void swp(vector<Mem> &v, int a, int b)
{
    for(int i = 0; i <= (b - a) / 2; i++ )
    {
        swap(v[a + i], v[b - i]);
    }
}
int main()
{
    int head, N, L;
    cin >> head >> N >> L;
    while(N--)
    {
        int addr, data, nxt;
        cin >> addr >> data >> nxt;
        mem[addr] = data;
        Next[addr] = nxt;
    }

    int p = head;
    int k = 0;
    while(p != -1)
    {
        Mem m;
        m.addr = p;
        m.data = mem[p];
        res.push_back(m);
        p = Next[p];
        k++;
    }

    for(int i = 0; i + L <= k; i += L)
    {
        swp(res, i, i + L - 1);
    }

    for(int i = 0; i < k; i++)
    {
        if(i == k - 1)
            printf("%05d %d -1\n", res[i].addr, res[i].data);
        else
            printf("%05d %d %05d\n", res[i].addr, res[i].data, res[i + 1].addr);
    }

    return 0;
}
