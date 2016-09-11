#include <iostream>
#include <string.h>
using namespace std;

int mice[1024], order[1024];
int NG, M;
int res[1024];

int contest(int cts[], int len, int win[])
{
    int grp = (len % M == 0 ? len / M : len / M + 1);
    int k = 0;

    for(int i = 0; i < grp; i++)
    {
        int m = -1;
        int mId = 0;
        for(int j = i * M; j < (i + 1) * M && j < len; j++)
        {
            if(mice[cts[j]] > m)
            {
                m = mice[cts[j]];
                mId = cts[j];
            }
        }
        win[k++] = mId;
        for(int j = i * M; j < (i + 1) * M && j < len; j++)
        {
            if(cts[j] != mId)
            {
                res[cts[j]] = grp + 1;
            }
        }
    }
    return grp;
}
int main()
{
    memset(res, 0, sizeof(res));
    cin >> NG >> M;
    for(int i = 0; i < NG; i++)
    {
        cin >> mice[i];
    }

    for(int i = 0; i < NG; i++)
    {
        cin >> order[i];
    }

    int len = NG;
    int win[1024];
    while(len != 1)
    {
        len = contest(order, len, win);
        for(int i = 0; i < len; i++)
        {
            order[i] = win[i];
        }
    }

    for(int i = 0; i < NG; i++)
    {
        if(res[i] != 0)
            cout << res[i] << (i == NG - 1 ? "\n" : " ");
        else
            cout << 1 << (i == NG - 1 ? "\n" : " ");
    }

    return 0;
}
