#include <iostream>
#include <string.h>
using namespace std;

int cnt[10005];
int num[100005];
int main()
{
    memset(cnt, 0, sizeof(cnt));
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        num[i] = n;
        cnt[n]++;
    }
    int i;
    for(i = 0; i < N; i++)
    {
        if(cnt[num[i]] == 1) break;
    }
    if(i < N)
        cout << num[i] << endl;
    else
        cout << "None" << endl;
    return 0;
}
