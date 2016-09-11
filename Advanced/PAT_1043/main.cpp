#include <iostream>
/**
8
3 2 1 8 6 5 7 9
*/
using namespace std;

typedef struct
{
    int value;
    int left;
    int right;
} Node;
Node tree[1024];

int N, node[1024];
int left[1024], right[1024];

int bst(int l, int r)
{
    int root = node[l];
    tree[l].value = node[l];

    if(l == r)
    {
        tree[l].left = tree[l].right = -1;
        return 1;
    }

    int i = l + 1;
    while(node[i] < root && i <= r) i++;

    int j = i;
    while(j <= r)
    {
        if(node[j] < root)
            return 0;
        j++;
    }
    if(i > r)
    {
        tree[l].left = l + 1;
        tree[l].right = -1;
        return bst(l + 1, i - 1);
    }
    if(i == l + 1)
    {
        tree[l].left = -1;
        tree[l].right = l + 1;
        return bst(i, r);
    }

    tree[l].left = l + 1;
    tree[l].right = i;

    return bst(l + 1, i - 1) && bst(i, r);
}

int mirror(int l, int r)
{
    int root = node[l];
    tree[l].value = node[l];

    if(l == r)
    {
        tree[l].left = tree[l].right = -1;
        return 1;
    }

    int i = l + 1;
    while(node[i] >= root && i <= r) i++;

    int j = i;
    while(j <= r)
    {
        if(node[j] >= root)
            return 0;
        j++;
    }
    if(i > r)
    {
        tree[l].left = l + 1;
        tree[l].right = -1;
        return mirror(l + 1, i - 1);
    }
    if(i == l + 1)
    {
        tree[l].left = -1;
        tree[l].right = l + 1;
        return mirror(i, r);
    }

    tree[l].left = l + 1;
    tree[l].right = i;

    return mirror(l + 1, i - 1) && mirror(i, r);
}

int first = 1;
void postOrder(int r)
{
    if(r == -1)
        return;
    postOrder(tree[r].left);
    postOrder(tree[r].right);
    if(first)
    {
        cout << tree[r].value;
        first = 0;
    }
    else
        cout << " " << tree[r].value;
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> node[i];
    }

    if(bst(0, N - 1) || mirror(0, N - 1))
    {
        cout << "YES" << endl;
        postOrder(0);
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
