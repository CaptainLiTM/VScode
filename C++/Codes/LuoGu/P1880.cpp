#include <iostream>
#define MAXN 220
#define INF 0x3f3f3f3f
using namespace std;
int n, a[MAXN];
int mem1[MAXN][MAXN], mem2[MAXN][MAXN];
int dfs1(int l, int r)
{
    if (mem1[l][r])
        return mem1[l][r];
    if (l == r)
        return mem1[l][r] = 0;
    int ans = INF;
    for(int i = l; i < r; i++)
        ans = min(ans, dfs1(l, i - 1) + dfs1(i, r) + a[r] - a[l - 1]);
    return mem1[l][r] = ans;
}
int dfs2(int l, int r)
{
    if (mem2[l][r])
        return mem2[l][r];
    if (l == r)
        return mem2[l][r] = 0;
    int ans = 0;
    for(int i = l; i < r; i++)
    {
        ans = max(ans, dfs2(l, i - 1) + dfs2(i, r) + a[r] - a[l - 1]);
    }
    return mem2[l][r] = ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2*n; i++)//前缀和
    {
        a[i] += a[i - 1]; 
    }
    dfs1(1, 2*n);
    dfs2(1, 2*n);
    int ans1 = INF, ans2 = 0;
    for(int i = 1; i <= n; i++)
    {
        ans1 = min(ans1, mem1[i][n+i-1]);
        ans2 = max(ans2, mem2[i][n+i-1]);
    }
    cout << ans1 << endl << ans2 << endl;
    system("pause");
    return 0;
}