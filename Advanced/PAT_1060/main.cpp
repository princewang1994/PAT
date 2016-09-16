#include <iostream>
#include <string.h>
#include <string>
using namespace std;
typedef struct
{
    string d;
    int exp;
}Number;

int N;
Number save(string n)
{
    int dot = n.find(".");

    Number nb;

    if(dot >= n.length())
    {
        nb.d = n;
        nb.exp = n.length();
    }
    else{
        if(n[0] == '0')
        {
            int exp = 1;
            n.erase(dot, 1);
            while(n[0] == '0' && n.size() > 0)
            {
                n.erase(0, 1);
                exp--;
            }
            if(n.size() == 0)
            {
                nb.exp = 0;
                nb.d = "0";
            }
            else
            {
                nb.exp = exp;
                nb.d = n;
            }
        }
        else
        {
            n.erase(dot, 1);
            nb.exp = dot;
            nb.d = n;
        }
    }
    if(nb.d.length() > N)
        nb.d.erase(N);
    else if(nb.d.length() < N)
    {
        while(nb.d.length() != N)
            nb.d.append("0");
    }

    return nb;
}
int out(Number n)
{
    cout << "0." << n.d << "*10^" << n.exp;
}
int main()
{
    string a, b;
    cin >> N >> a >> b;
    Number n1 = save(a);
    Number n2 = save(b);

    if(n1.d == n2.d && n1.exp == n2.exp)
    {
        cout << "YES" << " ";
        out(n1);
        cout << endl;
    }
    else{
        cout << "NO" << " ";
        out(n1);
        cout << " ";
        out(n2);
        cout << endl;
    }
    return 0;
}
