#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
map<string, int> mp;
int grade[4][2048];
int a[2048], c[2048], m[2048], e[2048];

int cmpA(int a, int b)
{
    return grade[0][a] < grade[0][b];
}
int cmpC(int a, int b)
{
    return grade[1][a] < grade[1][b];
}
int cmpM(int a, int b)
{
    return grade[2][a] < grade[2][b];
}
int cmpE(int a, int b)
{
    return grade[3][a] < grade[3][b];
}

int main()
{
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        string id;
        cin >> id;
        mp[id] = i;
        int C, M, E, A;
        cin >> C >> M >> E;
        A = int(C + M + E + 0.5);
        grade[0][i] = A;
        grade[1][i] = C;
        grade[2][i] = M;
        grade[3][i] = E;
        e[i] = i;
        a[i] = i;
        c[i] = i;
        m[i] = i;
    }

    sort(a, a + N, cmpA);
    sort(c, c + N, cmpC);
    sort(m, m + N, cmpM);
    sort(e, e + N, cmpE);

    for(int i = 0; i < N; i++)
    {

    }

    return 0;
}
