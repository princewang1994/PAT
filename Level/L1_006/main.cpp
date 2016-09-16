#include <iostream>
#include <vector>
using namespace std;
vector<int> mod;
int Max = -1;
int l;
int r;
void calc(int N)
{
    for(int i = 2; i <= N / 2; i++)
    {
        if(N % i == 0)
            mod.push_back(i);
    }
    for(int i = 0; i < mod.size(); i++)
    {
        long long prod = mod[i];
        int len = 0;
        int j = i + 1;
        while(prod < N  && (N % (prod * mod[j + 1]) == 0) && mod[j] == mod[j - 1] + 1 && j < mod.size())
        {
            prod *= mod[j++];
            len++;
        }
        if(N % prod == 0)
        {
            if(Max < len)
            {
                Max = len;
                l = i;
                r = j - 1;
            }
        }
    }
}
int main()
{
    int N;
    cin >> N;
    calc(N);
    if(Max == -1)
    {
        cout << 1 << endl;
        cout << N << endl;
        return 0;
    }
    cout << Max + 1 << endl;
    for(int i = l; i <= r; i++)
    {
        cout << mod[i] << (i == r ? "\n" : "*");
    }
    return 0;
}
