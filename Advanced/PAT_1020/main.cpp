#include <iostream>
#include <queue>
using namespace std;

typedef struct
{
    int value;
    int left;
    int right;
} Node;

Node node[32];
int postOrder[32];//后跟遍历
int midOrder[32];//中跟遍历
int N;

//递归函数， l1，r1表示后跟遍历的左界和右界
//l2， r2表示中根遍历的左界和右界
void f(int l1, int r1, int l2, int r2)
{
    int root = postOrder[r1];

    if(l1 == r1)
    {
        node[root].left = node[root].right = -1;
        return;
    }
    //i记录根在midOrder的位置
    int i = 0;
    while(midOrder[i] != root) i++;
    int cntL = i - l2;  //cntL表示i左边有几个元素，用于分隔postOrder

    if(i == l2)//左子树为空情况
    {
        node[root].left = -1;
        node[root].right = postOrder[r1 - 1];
        f(l1 + cntL, r1 - 1, i + 1, r2);
        return;
    }
    if(i == r2)//右子树为空情况
    {
        node[root].right = -1;
        node[root].left = postOrder[r1 - 1];
        f(l1, l1 + cntL - 1, l2, i - 1);
        return;
    }
    //两边都不为空，先求解两根
    f(l1, l1 + cntL - 1, l2, i - 1);
    f(l1 + cntL, r1 - 1, i + 1, r2);

    //最后给根赋值
    node[root].left = postOrder[l1 + cntL - 1];
    node[root].right = postOrder[r1 - 1];

}
//层次遍历
void bfs()
{
    int root = postOrder[N - 1];
    queue<int> q;
    q.push(root);
    int first = 1;
    while(!q.empty())
    {
        int v = q.front();
        if(first)
        {
            first = 0;
            cout << v;
        }
        else
        {
            cout << " " << v;
        }
        q.pop();
        if(node[v].left != -1)
            q.push(node[v].left);
        if(node[v].right != -1)
            q.push(node[v].right);
    }
}
int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> postOrder[i];
    }
    for(int i = 0; i < N; i++)
    {
        cin >> midOrder[i];
    }

    f(0, N - 1, 0, N - 1);

    bfs();

    return 0;
}
