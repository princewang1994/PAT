#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

int nMap[100000];
int vst [100000];
int main()
{
    int add1, add2;
    int N;
    cin >> add1 >> add2 >> N;
    char c;
    memset(vst, 0, sizeof(vst));

    while(N--)
    {
        int add, next;
        cin >> add >> c >> next;
        nMap[add] = next;
    }
    int p = add1;
    while(p != -1)
    {
        vst[p] = 1;
        p = nMap[p];
    }

    p = add2;
    while(p != -1)
    {
        if(vst[p])
            break;
        p = nMap[p];
    }
    if(p == -1)
        cout << -1 << endl;
    else
        printf("%05d", p);

    return 0;
}
