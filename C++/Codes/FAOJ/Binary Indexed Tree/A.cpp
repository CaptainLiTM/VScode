#include <iostream>
#define MAX 100000
using namespace std;
int tree[MAX], n, m;
inline int lowbit(int x)
{
    return x & -x;
}
void change(int x, int y)
{
    while (x <= n)
    {
        tree[x] += y;
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
    cin >> n >> m;
    char a;
    int b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        if (a == 'C')
            change(b, c);
        if (a == 'P')
            cout << sum(c) - sum(b - 1) << endl;
    }
    system("pause");
    return 0;
}