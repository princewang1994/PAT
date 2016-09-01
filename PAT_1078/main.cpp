#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int isPrime(int n)
{
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int Hash[10005];
int main()
{
    memset(Hash, 0, sizeof(Hash));

    int MSize, N;
    cin >> MSize;
    while(!isPrime(MSize))
    {
        MSize++;
    }
    cin >> N;
    while(N--)
    {
        int key;
        cin >> key;

        int i;
        for(i = 0; i < MSize; i++)
        {
            if(Hash[(key + i * i) % MSize] == 0)
            {
                Hash[(key + i * i) % MSize] = 1;
                cout << (key + i*i) % MSize << (N ? " " : "\n");
                break;
            }
        }

        if(i == MSize)
        {
            cout << "-" << (N ? " " : "\n");
        }
    }
    return 0;
}
