#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
typedef struct
{
    string name;
    int age;
    int wealth;
} Person;

int M, N;
vector< vector<Person> > person;

int cmp(Person p1, Person p2)
{
    if(p1.wealth != p2.wealth)
        return p1.wealth > p2.wealth;
    else
        return p1.name < p2.name;
}
void init()
{
    person.resize(201);
    cin >> M >> N;
    while(M--)
    {
        Person p;
        cin >> p.name >> p.age >> p.wealth;
        person[p.age].push_back(p);
    }
    for(int i = 0; i <= 200; i++)
    {
        if(person.size() != 0)
        {
            sort(person[i].begin(), person[i].end(), cmp);
        }
    }
}
void query(int m, int Amin, int Amax, vector<Person> &res)
{
    int p[205];
    memset(p, 0, sizeof(p));

    while(m--)
    {
        int Max = -1000005;
        int ptr = Amin;
        for(int i = Amin; i <= Amax; i++)
        {
           if(person[i].size() > 0)
           {
               if(p[i] < person[i].size() && person[i][p[i]].wealth > Max)
               {
                    Max = person[i][p[i]].wealth;
                    ptr = i;
               }
           }
        }
        if(Max != -1000005)
        {
            res.push_back(person[ptr][p[ptr]]);
            p[ptr]++;
        }
        else break;
    }
}
void output(vector<Person> &ans)
{
    if(ans.size() == 0)
    {
        cout << "None" << endl;
        return;
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].name << " " << ans[i].age << " " << ans[i].wealth << endl;
    }
}
int main()
{
    init();
    for(int i = 1; i <= N; i++)
    {
        int m, Amin, Amax;
        vector<Person> ans;
        cin >> m >> Amin >> Amax;
        query(m, Amin, Amax, ans);
        cout << "Case #" << i << ":" << endl;
        output(ans);
    }
    return 0;
}
