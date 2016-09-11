#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int M, N, K;
    cin >> M >> N >> K;

    while(K--)
    {
        int n = N;
        int flag = 1;
        int seq = 1;
        while(n--)
        {
            int in;
            cin >> in;
            while(seq <= in)
            {
                s.push(seq++);
            }
            if(in < s.top() || s.size() > M)
            {
                flag = 0;
            }
            s.pop();
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
