#include <iostream>
#define MAX 1010
using namespace std;
int n, m, fa[MAX * MAX], ans;
bool v[MAX * MAX];
char b;
int id(int i, int j) { return (i - 1) * m + j; }
int finds(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = finds(fa[x]);
}
void unions(int x, int y)
{
    int fx = finds(x), fy = finds(y);
    if (fx != fy)
        fa[fx] = fy;
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> b;
            if (b == 'E')
                unions(id(i, j), id(i, j + 1));
            if (b == 'W')
                unions(id(i, j), id(i, j - 1));
            if (b == 'N')
                unions(id(i, j), id(i - 1, j));
            if (b == 'S')
                unions(id(i, j), id(i + 1, j));
        }
    }
    for (int i = 1; i <= n * m; i++)
    if (!v[finds(i)])
    {
        ans++;
        v[finds(i)] = 1;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}