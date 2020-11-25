#include <iostream>
#define MAXN 40
#define n2 n*n
using namespace std;
int n, a[MAXN][MAXN];
void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << a[i][j] << " ";
        cout << a[i][n] << endl;
    }
    return;
}
void build(int k, int x, int y)
{
    if (k == n2 + 1)
        return;
    else if (k == 1)
    {
        a[1][(n + 1) / 2] = k;
        build(k + 1, 1, (n + 1) / 2);
    }
    else if (x == 1 && y != n)
    {
        a[n][y + 1] = k;
        build(k + 1, n, y + 1);
    }
    else if (x != 1 && y == n)
    {
        a[x - 1][1] = k;
        build(k + 1, x - 1, 1);
    }
    else if (x == 1 && y == n)
    {
        a[x + 1][y] = k;
        build(k + 1, x + 1, y);
    }
    else if (x != 1 && y != n && !a[x - 1][y + 1])
    {
        a[x - 1][y + 1] = k;
        build(k + 1, x - 1, y + 1);
    }
    else
    {
        a[x + 1][y] = k;
        build(k + 1, x + 1, y);
    }
    return;
}
int main()
{
    /*freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);*/
    ios::sync_with_stdio(false);
    cin >> n;
    build(1, 0, 0);
    print();
    system("pause");
    return 0;
}