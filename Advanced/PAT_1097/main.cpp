#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
using namespace std;

int mem[100005];
int Next[100005];
int first[10005];
int rmHead = -1;
int rmTail = -1;

void rm(int pre, int addr)
{
    Next[pre] = Next[addr];
    if(rmHead == -1)
    {
        rmHead = rmTail = addr;
        Next[rmTail] = -1;
    }
    else{
        Next[addr] = -1;
        Next[rmTail] = addr;
        rmTail = addr;
    }
}
int main()
{
    memset(first, 0, sizeof(first));

    int head, N;
    cin >> head >> N;
    while(N--)
    {
        int addr, data, nxt;
        cin >> addr >> data >> nxt;
        mem[addr] = data;
        Next[addr] = nxt;
    }
    int ptr = head, pre = -1;
    while(ptr != -1)
    {
        int data = abs(mem[ptr]);
        if(!first[data])
        {
            first[data] = 1;
            pre = ptr;
            ptr = Next[ptr];
        }
        else{
            int tmp = Next[ptr];
            rm(pre, ptr);
            ptr = tmp;
        }
    }

    ptr = head;
    while(ptr != -1)
    {
        if(Next[ptr] != -1)
            printf("%05d %d %05d\n", ptr, mem[ptr], Next[ptr]);
        else
            printf("%05d %d -1\n", ptr, mem[ptr]);
        ptr = Next[ptr];
    }

    ptr = rmHead;
    while(ptr != -1)
    {
        if(Next[ptr] != -1)
            printf("%05d %d %05d\n", ptr, mem[ptr], Next[ptr]);
        else
            printf("%05d %d -1\n", ptr, mem[ptr]);
        ptr = Next[ptr];
    }
    return 0;
}
