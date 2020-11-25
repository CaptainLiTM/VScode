#include <iostream>
#include <string>
using namespace std;
int l, r, ans;
int main()
{
    freopen("two.in", "r", stdin);
    freopen("two.out", "w", stdout);
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (i % 10 == 2)
            ans++;
        if (i / 10 % 10 == 2)
            ans++;
        if (i / 100 % 10 == 2)
            ans++;
        if (i / 1000 % 10 == 2)
            ans++;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}