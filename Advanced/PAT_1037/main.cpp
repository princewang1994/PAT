#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long> coup;
vector<long> prod;

int main()
{
    int NC, NP;
    cin >> NC;
    for(int i = 0; i< NC; i++)
    {
        long c;
        cin >> c;
        coup.push_back(c);
    }
    cin >> NP;
    for(int i = 0; i< NP; i++)
    {
        long p;
        cin >> p;
        prod.push_back(p);
    }
    sort(coup.begin(), coup.end());
    sort(prod.begin(), prod.end());

    int i = coup.size() - 1, j = prod.size() - 1;

    long long sum = 0;
    while(coup[i] * prod[j] > 0 && i >= 0 && j >= 0)
    {
        sum += coup[i] * prod[j];
        i--, j--;
    }

    if(i >= 0 && j >= 0)
    {
        i = 0, j = 0;
        while(coup[i] * prod[j] > 0 && i < NC && j < NP)
        {
            sum += coup[i] * prod[j];
            i++,j++;
        }
    }
    cout << sum << endl;
    return 0;
}
