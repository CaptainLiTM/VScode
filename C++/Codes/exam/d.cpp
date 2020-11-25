#include <iostream>
#include <cstring>
#define MAX 1010
using namespace std;
int n, m, ans;
char c[MAX][MAX];
bool v[MAX][MAX];
void s(int x, int y)
{
    if (v[x][y] == false)
    {
        ans++;
        return;
    }
    v[x][y] = false;
    if (c[x][y] == 'N')
        s(x - 1, y);
    else if (c[x][y] == 'S')
        s(x + 1, y);
    else if (c[x][y] == 'W')
        s(x, y - 1);
    else if (c[x][y] == 'E')
        s(x, y + 1);
    return;
}
int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    memset(v, true, sizeof(v));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (v[i][j] == true)
            {
                s(i, j);
            }
        }
    cout << ans << endl;
    //system("pause");
    return 0;
}