#include <iostream>

using namespace std;

int main()
{
    long N;
    cin >> N;

    cout << N << "=";
    if(N == 1)
    {
        cout << "1" << endl;
        return 0;
    }

    int first = 1;
    for(int i = 2; i <= N; i++)
    {
        int exp = 0;
        if(N % i == 0)
        {

            while(N % i == 0)
            {
                N /= i;
                exp++;
            }

            if(first)
            {
                first = 0;
                if(exp > 1)
                    cout << i << "^" << exp;
                else
                    cout << i;
            }
            else{

                if(exp > 1)
                    cout << "*" << i << "^" << exp;
                else
                    cout << "*" << i;
            }
        }
    }
    cout << endl;
    return 0;
}
