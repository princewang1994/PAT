#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef struct
{
    int left;
    int right;
} Node;

typedef struct
{
    int index;
    int value;
} Value;

Node node[128];
int num[128];

int len = 0;
Value value[128];

int cmp1(Value v1, Value v2)
{
    return v1.index < v2.index;
}
int cmp2(Value v1, Value v2)
{
    return v1.value < v2.value;
}

int bfs()
{
    queue<int> q;
    q.push(0);

    int k = 0;
    int first = 1;
    while(!q.empty())
    {
        int x = q.front();
        if(first)
        {
            first = 0;
            cout << value[x].value;
        }
        else
            cout << " " << value[x].value;

        q.pop();
        if(node[x].left != -1)
            q.push(node[x].left);
        if(node[x].right != -1)
            q.push(node[x].right);
    }
    return k;
}

void mid(int root)
{
    if(root == -1)
        return;

    mid(node[root].left);
    value[len++].index = root;
    mid(node[root].right);
}
int main()
{
    int N;
    cin >> N;
    int k = 0, n = N;

    while(n--)
    {
        int r, l;
        cin >> l >> r;
        node[k].left = l;
        node[k++].right = r;
    }

    for(int i = 0; i < N; i++)
    {
        cin >> value[i].value;
    }

    sort(value, value + N, cmp2);
    mid(0);
    sort(value, value + N, cmp1);
    bfs();
    return 0;
}
