#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#define ll long long
#define MAXANS 200020
using namespace std;
ll l, r, amount, ans[MAXANS];
ll get_y(ll k)
{
    ll ansy;
    for (ll i = 1; i <= k; i++)
        if (k % i == 0)
            ansy++;
    return ansy;
}
ll get_x(ll k)
{
    set<ll> s2;
    for (ll i = 1; i < k; i++)
        for (ll j = 1; j <= i; j++)
            if (i % j == 0)
                s2.insert(j);
    return s2.size();
}
int main()
{
    cin >> l >> r;
    if (l == 1)
        l++;
    for (ll i = l; i <= r; i++)
    {
        if (get_y(i) > get_x(i))
        {
            ans[++amount] = i;
        }
    }
    cout << amount << " ";
    for (int i = 1; i <= amount; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}