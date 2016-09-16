#include <iostream>
#include <algorithm>

using namespace std;
typedef struct
{
    int idx;
    int num;
}Num;

int n[1024];
Num num[1024];
int N;
int k = 0;
void midRoot(int a, Num *num)
{
    if(a > N)
        return;
    midRoot(a << 1, num);
    num[k++].idx = a - 1;
    midRoot((a << 1) + 1, num);
}
int cmp(Num n1, Num n2)
{
    return n1.idx < n2.idx;
}
int cmp2(Num n1, Num n2)
{
    return n1.num < n2.num;
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num[i].num;
    }
    sort(num, num + N, cmp2);
    midRoot(1, num);
    sort(num, num + N, cmp);
    for(int i = 0; i < N; i++)
    {
        cout << num[i].num << (i == N - 1 ? "\n" : " ");
    }
    return 0;
}
