#include <iostream>
#include <string>
#define MAX 100100
using namespace std;
int n, m;
struct toy
{
    string name;
    bool direction;
}t[MAX];
int main()
{
    //freopen("toy.in", "w", stdin);
    //freopen("toy.out", "r", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i].direction >> t[i].name;
    }
    int now = 1, d;
    for (int i = 1; i <= m; i++)
    {
        bool command1;
        int command2;
        cin >> command1 >> command2;
        if (t[now].direction ^ command1)
        {
            if (now + command2 > n)
                now = now + command2 - n;
            else
                now += command2;
        }
        else
        {
            if (now - command2 <= 0)
                now = now - command2 + n;
            else 
                now -= command2;
        }
    }
    cout << t[now].name << endl;
    system("pause");
    return 0;
}