#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int equals(int * a, int l1, int * b, int l2)
{
    if(l1  != l2)
        return 0;
    for(int i = 0; i < l1; i++)
    {
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}
int Double(int a[], int len, int b[])
{
    int carry = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        b[i] = a[i] * 2;
        if(carry)
        {
            b[i] += 1;
        }
        if(b[i] >= 10)
        {
            b[i] -= 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
    }
    if(carry)
    {
        for(int i = len - 1; i >= 0; i--)
        {
            b[i + 1] = b[i];
        }
        b[0] = 1;
        return len + 1;
    }
    return len;
}
int cp(char a[], int b[])
{
    int k = 0;
    for(int i = 0; a[i] != 0; i++)
    {
        b[k++] = a[i] - '0';
    }
    return k;
}
int main()
{
    char src[32];
    char dst[32];
    int a[100], b[100];
    int res[100];

    cin >> src;
    int l1 = cp(src, a);
    int l2 = Double(a, l1, b);

    for(int i = 0; i < l2; i++)
    {
        res[i] = b[i];
    }
    sort(a, a + l1);
    sort(b, b + l2);

    if(equals(a, l1, b, l2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    for(int i = 0; i < l2; i++)
    {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
