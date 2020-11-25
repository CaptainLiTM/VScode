#include <iostream>
#include <cstring>
#define MAXM 110
#define INF 0x3f3f3f3f
using namespace std;
int n, t;
int tcost[MAXM], mget[MAXM];
int mem[MAXM][MAXM * 10];
int dfs(int pos, int tleft)
{
    if (mem[pos][tleft] != -1)
        return mem[pos][tleft];
    if (pos == n + 1)
        return mem[pos][tleft] = 0;
    int dfs1, dfs2 = -INF;
    dfs1 = dfs(pos + 1, tleft);
    if (tleft >= tcost[pos])
        dfs2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos];
    return mem[pos][tleft] = max(dfs1, dfs2);
}
int main()
{
    memset(mem, -1, sizeof(mem));
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
        cin >> tcost[i] >> mget[i];
    cout << dfs(1, t) << endl;
    return 0;
}