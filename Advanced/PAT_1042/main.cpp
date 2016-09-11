#include <iostream>

using namespace std;
typedef struct
{
    char face;
    int value;
} Card;
char face[] = {'S', 'H', 'C', 'D'};
Card card[2][56];
int order[56];
int N, src = 0, dest = 1;

void init()
{
    int k = 1;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= 13; j++)
        {
            Card c;
            c.face = face[i];
            c.value = j;
            card[0][k++] = c;
        }
    }
    Card c;
    c.face = 'J';
    c.value = 1;
    card[0][k++] = c;
    c.value = 2;
    card[0][k++] = c;
}
void shuffle()
{
    for(int i = 1; i <= 54; i++)
    {
        int pos = order[i];
        card[dest][pos] = card[src][i];
    }
    src = !src;
    dest = !dest;
}
int main()
{
    init();
    cin >> N;
    for(int i = 1; i <= 54; i++)
    {
        cin >> order[i];
    }
    while(N--)
    {
        shuffle();
    }
    int first = 1;
    for(int i = 1; i <= 54; i++)
    {
        if(first)
        {
            cout << card[src][i].face << card[src][i].value;
            first = 0;
        }
        else
            cout <<  " " << card[src][i].face << card[src][i].value;

    }
    cout << endl;
    return 0;
}
