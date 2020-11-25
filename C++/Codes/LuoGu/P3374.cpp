#include <iostream>
#define MAX 500010
using namespace std;
int n, m, tree[MAX];
inline int lowbit(int k)
{
    return k & -k;
}
void change(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
    return;
}
int sum(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    int i, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        change(i, a);
    }
    while (m--)
    {
        cin >> a >> b >> c;
        if (a == 1)
            change(b, c);
        else if (a == 2)
            cout << sum(c) - sum(b - 1) << endl;
    }
    system("pause");
    return 0;
}