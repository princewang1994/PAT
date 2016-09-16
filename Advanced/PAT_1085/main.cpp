#include <iostream>
#include <algorithm>

using namespace std;
int num[100005];
int main()
{
    int N;
    long p;
    cin >> N >> p;
    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    int cnt = 0;
    int j = 0;
    for(int i = 0; i < N; i++)
    {
        long Min = num[i];
        long long m = Min * p;
        for(; num[j] <= m && j < N; j++);

        if(j - i > cnt)
            cnt = j - i;
    }
    cout << cnt << endl;
    return 0;
}
