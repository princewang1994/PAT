#include <iostream>
#include <string>
using namespace std;

string str = "\t";
int Max = -1;
int isSame(int l, int h)
{
    for(int i = l + 1; i <= h; i++)
    {
        if(str[i] != str[l])
            return 0;
    }
    return 1;
}
int main()
{
    string s;
    getline(cin, s);
    str.append(s);

    if(s.length() == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int high = 0, low = 0;
    for(int i = 1; i < str.length(); i++)
    {
        if(low - 1 >= 0 && str[low - 1] == str[i])
        {
            low = low - 1;
            high = i;
        }
        else if(isSame(low, high) && str[low] == str[i])
        {
            high = i;
        }
        else
        {
            low = high = i;
        }

        if(high - low + 1 > Max)
            Max = high - low + 1;
    }
    cout << Max << endl;
    return 0;
}
