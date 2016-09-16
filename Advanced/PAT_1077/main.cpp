#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str[256];
    int ptr[256];
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++)
    {
        getline(cin, str[i]);
        ptr[i] = str[i].length() - 1;
    }

    int finish = 0;
    while(1)
    {
        for(int i = 0; i < N; i++)
        {
            if(ptr[i] < 0)
            {
                finish = 1;
                break;
            }
            if(str[i][ptr[i]] != str[0][ptr[0]])
            {
                finish = 1;
                break;
            }
        }
        if(!finish)
        {
            for(int i = 0; i < N; i++) ptr[i]--;
        }
        else break;
    }

    if(ptr[0] != str[0].length() - 1)
        cout << str[0].substr(ptr[0] + 1) << endl;
    else
        cout << "nai" << endl;

    return 0;
}
