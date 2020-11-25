#include <iostream>
#include <algorithm>
#define MAXM 200020
#define MAXN 5005
using namespace std;
int n, m, cnt=0;
int fa[MAXN];
int eu, ev, ans=0;
struct edge
{
    int u, v, w;
} e[MAXM];//链式前向星
int find(int x)//并查集+路径压缩
{
    while(x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
inline bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void kruskal()
{
    sort(e + 1, e + m + 1, cmp);//按权值对边进行排序
    for(int i = 1; i <= m; i++)//再遍历所有边
    {
        eu = find(e[i].u), ev = find(e[i].v);
        if(eu == ev)//应用并查集，若属于同一个集合，则跳过这条边
            continue;
        ans += e[i].w;
        fa[eu] = ev;//启发式合并：每次将较小的并入大的集合
        if(++cnt == n-1)
            break;
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;//并查集初始化
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    cout << ans << endl;
    system("pause");
    return 0;
}