#include <iostream>
#include <vector>
using namespace std;

void merge(vector<long> a, vector<long> & res)
{
    int N;
    cin >> N;
    int i = 0;
    while(N--)
    {
        long num;
        cin >> num;
        if(a[i] < num)
        {
            while(a[i] < num && i != a.size())
            {
                res.push_back(a[i]);
                i++;
            }
            res.push_back(num);
            if(i == a.size())
            {
                break;
            }
        }
        else
        {
            res.push_back(num);
        }
    }

    if(i == a.size())
    {
        while(N--)
        {
            long num;
            cin >> num;
            res.push_back(num);
        }
    }
    else{
        while( i != a.size())
        {
            res.push_back(a[i]);
            i++;
        }
    }
}

int main()
{
    vector<long> a;
    int N;
    cin >> N;
    int n = N;
    while(n--)
    {
        long num;
        cin >> num;
        a.push_back(num);
    }

    vector<long> res;
    merge(a, res);
    cout << res[(res.size() - 1) / 2] << endl;
    return 0;
}
