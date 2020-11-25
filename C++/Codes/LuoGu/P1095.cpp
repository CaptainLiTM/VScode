#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 300001
using namespace std;
int m, s, t;
int mem[MAX];
int main()
{
    cin >> m >> s >> t;
    memset(mem, 0, sizeof(mem));
    for (int i = 1; i <= t; i++)
    {
        if (m >= 10)
        {
            m -= 10;
            mem[i] = mem[i - 1] + 60;
        }
        else
        {
            mem[i] = mem[i - 1];
            m += 4;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        mem[i] = max(mem[i - 1] + 17, mem[i]);
        if (mem[i] >= s)
        {
            cout << "Yes" << endl << i << endl;
            system("pause");
            return 0;
        }
    }
    if (mem[t] < s)
        cout << "No" << endl << mem[t];
    system("pause");
    return 0;
}