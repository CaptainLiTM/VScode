#include <iostream>
#define MAX 300010
#define w (i - 1) * m + j
using namespace std;
int n, m, q;
int x,y;
int square[10000][10000];
void adjust(int x, int y)
{
    for (register int i = y; i < m; i++)
    {
        swap(square[x][i], square[x][i + 1]);
    }
    for (register int i = x; i < m; i++)
    {
        swap(square[i][y], square[i + 1][y]);
    }
}
int main()
{
    cin >> n >> m >> q;
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= m; j++)
            square[i][j] = w;
    for (register int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        cout << square[x][y] << endl;
        adjust(x, y);
    }
    system("pause");
    return 0;
}