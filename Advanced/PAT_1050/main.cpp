#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    char s1[10005];
    char s2[10005];
    int del[512];
    memset(del, 0, sizeof(del));

    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    for(int i = 0; str2[i] != 0; i++)
    {
        del[str2[i]] = 1;
    }
    for(int i = 0; str1[i] != 0; i++)
    {
        if(!del[str1[i]])
        {
            cout << str1[i];
        }
    }
    cout << endl;

    return 0;
    //以下是C语言代码

    gets(s1);
    gets(s2);

    for(int i = 0; s2[i] != 0; i++)
    {
        del[s2[i]] = 1;
    }
    for(int i = 0; s1[i] != 0; i++)
    {
        if(!del[s1[i]])
        {
            printf("%c", s1[i]);
        }
    }
    printf("\n");
    return 0;
}
