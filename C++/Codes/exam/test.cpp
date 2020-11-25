#include <iostream>
#include <cmath>
#include <set>
#define ll long long 
using namespace std;
int n, ans, m, mem[200010];
set<int> s;
ll get_y(ll k)
{
    if (mem[k])
        return mem[k];
    int ansy = 0;
    for (int i = 1; i <= k/2; i++)
        if (k % i == 0)
            ansy++;
    mem[k] = ansy;
    return ansy;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            s.insert(i);
    }
    for (int i = 1; i <= m; i++)
        if (m % i == 0)
            ans++;
    cout << s.size() << ans << get_y(n);
    system("pause");
}