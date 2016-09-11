#include <iostream>
#include <algorithm>
using namespace std;

int N, num[128], sorted[128];
int ind = 0;
int isEqual()
{
    for(int i = 1; i <= N; i++)
    {
        if(num[i] != sorted[i])
            return 0;
    }
    return 1;
}
int isInsertSort()
{
    for(int i = 2; i <= N; i++)
    {
        sort(num, num + i);
        if(isEqual())
        {
            ind = i + 1;
            return 1;
        }
    }
    return 0;
}
void insertSort()
{
    sort(sorted, sorted + ind);
}
void print()
{
    for(int i = 1; i <= N; i++)
    {
        cout << sorted[i] << (i == N ? "\n" : " ");
    }
}
void heapSort()
{
    int len = N;
    while(len > 0 && sorted[len] >= sorted[1])
        len--;
    if(len == 0 )return;
    len--;
    pop_heap(sorted + 1, sorted + len + 1);
}
int main()
{
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }
    for(int i = 1; i <= N; i++)
    {
        cin >> sorted[i];
    }
    if(isInsertSort())
    {
        cout << "Insertion Sort" << endl;
        insertSort();
    }
    else
    {
        cout << "Heap Sort" << endl;
        heapSort();
    }
    print();

    return 0;
}
