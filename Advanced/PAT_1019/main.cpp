#include <iostream>
#include <stack>
using namespace std;

int radix(long n, long r, long num[])
{
    if(n == 0)
    {
        num[0] = 0;
        return 1;
    }
    int k = 0;
    while(n > 0)
    {
        num[k] = n % r;
        n /= r;
        k++;
    }
    return k;
}
int isPalindromic(long num[], int len)
{
    for(int i = 0; i <= len / 2; i++ )
    {
        if(num[i] != num[len - i - 1])
            return 0;
    }
    return 1;
}
int main()
{
    long N;
    long base;
    long num[10000];
    stack<long> s;
    cin >> N >> base;

    int len = radix(N, base, num);

    for(int i = 0; i < len; i++ )
    {
        s.push(num[i]);
    }
    if(isPalindromic(num, len))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    while(!s.empty())
    {
        long t = s.top();
        s.pop();
        if(s.empty())
            cout << t;
        else
            cout << t << " ";
    }
    return 0;
}
