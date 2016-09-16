#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int N, L, H;
typedef struct
{
    int id;
    int vir;
    int tal;
    int r;
}Person;
vector<Person> person;
int cmp(Person a, Person b)
{
    if(a.r != b.r)
        return a.r > b.r;

    if(a.vir + a.tal != b.vir + b.tal)
    {
        return a.vir + a.tal > b.vir + b.tal;
    }
    if(a.vir != b.vir)
        return a.vir > b.vir;
    return a.id < b.id;
}
void grade(Person &p)
{
    if(p.vir >= H && p.tal >= H)
    {
            p.r = 4;
            return;
    }
    if(p.vir >= H && p.tal < H)
    {
            p.r = 3;
            return;
    }
    if(p.vir < H && p.tal < H && p.vir >= p.tal)
    {
            p.r = 2;
            return;
    }
    p.r = 1;
}
int main()
{
    cin >> N >> L >> H;
    while(N--)
    {
        Person p;
        cin >> p.id >> p.vir >> p.tal;
        grade(p);
        if(p.tal >= L && p.vir >= L)
            person.push_back(p);
    }
    sort(person.begin(), person.end(), cmp);
    cout << person.size() << endl;
    for(int i = 0; i < person.size();
    i++)
    {
        printf("%08d %d %d\n", person[i].id, person[i].vir, person[i].tal);
    }
    return 0;
}
