#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 10010
#define MAXM 50010
#define MAXW 1000000000
#define INF 0x7fffffff
using namespace std;
int n, m, b;
int u, v, w;
int head[MAXN], tot, dis[MAXN];
bool vis[MAXN];
struct edge
{
    int next, to, w;
} e[MAXM];
inline void add_edge(int u, int v, int w)
{
    e[++tot].next = head[u];
    e[tot].to = v;
    e[tot].w = w;
    head[u] = tot;
    return;
}
int f[MAXN], f1[MAXN];
queue<int> q;
bool spfa(int top)
{
    dis[1] = 0;
    vis[1] = true;
    q.push(1);
    while (!q.empty())
    {
        u = q.front();
        vis[u] = false;
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            v = e[i].to;
            if (dis[v] > dis[u] + e[i].w && f[v] <= top)
            {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if (dis[n] < b)
        return true;
    else
        return false;
}
int main()
{
    memset(dis, INF, sizeof(dis));
    cin >> n >> m >> b;
    for (register int i = 1; i <= n; i++)
    {
        cin >> f[i];
        f[i] = f1[i];
    }
    for (register int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    if (!spfa(INF))
    {
        cout << "AFK" << endl;
        return 0;
    }
    sort(f1 + 1, f1 + 1 + n);
    int l = 1, r = MAXN, mid = (l + r) >> 1;
    while (l <= r)
    {
        int c = spfa(mid);
        if (c)
        {
            r = mid - 1;
            mid = (l + r) >> 1;
        }
        else
        {
            l = mid + 1;
            mid = (l + r) >> 1;
        }
    }
    cout << l << endl;
    system("pause");
    return 0;
}