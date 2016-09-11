#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(string ss1, string ss2)
{
    string s1 = ss1;
    string s2 = ss2;
    if(s1.length() == s2.length())
        return s1 < s2;
    if(s1.length() > s2.length())
    {
        int diff = s1.length() - s2.length();
        s2.append(s1.substr(0, diff));
    }
    else
    {
        int diff = s2.length() - s1.length();
        s1.append(s2.substr(0, diff));
    }
    if( s1 != s2)
        return s1 < s2;
    else
    {
        return ss1 + ss2 < ss2 + ss1;
    }
}
int isZero(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != '0')
            return 0;
    }
    return 1;
}
int main()
{
    int N;
    cin >> N;
    vector<string> v[10];

    int allZero = 1;
    while(N--)
    {
        string s;
        cin >> s;
        if(allZero)
        {
            if(!isZero(s))
                allZero = 0;
        }
        v[s[0] - '0'].push_back(s);
    }
    string res;
    for(int i = 0; i < 10; i++)
    {
        sort(v[i].begin(), v[i].end(), cmp);
    }

    for(int i = 0; i < 10; i++)
    {
        if(v[i].size() != 0)
            for(int j = 0; j < v[i].size(); j++)
            {
                res.append(v[i][j]);
            }
    }

    if(allZero)
    {
        cout << 0 << endl;
        return 0;
    }
    int i = 0;
    while(res[i] == '0')
        i++;
    while(i < res.size())
    {
        cout << res[i++];
    }
    cout << endl;
    return 0;
}
