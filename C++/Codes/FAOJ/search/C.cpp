#include <iostream>
#include <string>
#include <map>
#define MAXM 25
using namespace std;
map<string, int> pos;
int m, n, p;
int name[MAXM];
string s[7] = 
{
    "Today is Sunday.",
    "Today is Monday.",
    "Today is Tuesday.",
    "Today is Wednesday.",
    "Today is Thursday.",
    "Today is Friday.",
    "Today is Saturday."
}
int main()
{
    cin >> m >> n >> p;
    for (int i = 1; i <= m; i++)
    {
        cin >> name[i];
    }
}