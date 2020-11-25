#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 10005
#define MAXM 500005
#define INF 2147483647
using namespace std;
int n, m, s;
int u, v, w;
queue<int> q;
struct edge
{
    int next, to, w;
} e[MAXM];                          //链式前向星
int dis[MAXN], head[MAXN], tot = 0; //dis数组存储每个点到起点s的距离
bool vis[MAXN];                     //vis数组表明点是否在队列中
void add_edge(int u, int v, int w)
{
    e[++tot].next = head[u];
    e[tot].to = v;
    e[tot].w = w;
    head[u] = tot;
    return;
} //链式前向星加边
void spfa()
{
    memset(dis, INF, sizeof(dis)); //初始化dis为无穷大方便比较
    dis[s] = 0;                    //起点到自己的距离当然为0
    vis[s] = true;                 //先将起点入队
    q.push(s);
    int u, v;
    while (!q.empty())
    {
        u = q.front(); //每次取队头
        q.pop();       //弹出队头
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].next)
        { //遍历u的所有出边
            v = e[i].to;
            if (dis[v] > dis[u] + e[i].w)
            { //松弛操作 此时dis[u]已最优，遍历所有出边来寻找dis[v]的最优解
                dis[v] = dis[u] + e[i].w;
                if (!vis[v])
                { //将u链接的点放入队列，已在其中的就不用放了
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return;
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w); //存边，这里是单向边
        //add_edge(v, u, w); //存双向边
    }
    spfa();
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}
