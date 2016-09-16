#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;
set<int> s[64];
int main()
{
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int n;
            cin >> n;
            s[i].insert(n);
        }
    }
    int K;
    cin >> K;
    while(K--)
    {
        set<int> res;
        int id1, id2;
        cin >> id1 >> id2;
        set_intersection(s[id1].begin(), s[id1].end(), s[id2].begin(), s[id2].end(), inserter(res, res.begin()));
        int Nc = res.size();
        int Nt = s[id1].size() + s[id2].size() - Nc;
        printf("%.1f%%", double(Nc) / double(Nt) * 100);
    }
    return 0;
}
