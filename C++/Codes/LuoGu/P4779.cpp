#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 100010;
const int MAXM = 500010;
int n, m, s;
int u, v, w;
int tot = 0, head[MAXN], dis[MAXN];
bool vis[MAXN];
struct edge
{
    int next, to, w;
} e[MAXM];
void add_edge(int u, int v, int m)
{
    e[++tot].next = head[u];
    e[tot].to = v;
    e[tot].w = w;
    head[u] = tot;
    return;
}
struct node
{
    int w;//节点到起点距离
    int pos;//该节点编号
    bool operator<(const node &x) const
    { //重载运算符 < 使优先队列可以使用
        return x.w < w;
    }
};
priority_queue<node> q;//优先队列，利用堆优化dijkstra
void dijkstra()
{
    dis[s] = 0;
    q.push((node){0, s});//塞入队列，这里相当于node一个新变量，node.w=0，node.pos=s,再将它塞入队列
    while (!q.empty())//和spfa同样的终止条件：队列空
    {
        int u = q.top().pos;//取队头，这里我们只需要队头的编号就OK
        q.pop();//出队
        if (vis[u])//若该点找过，则跳过
            continue;
        vis[u] = true;//标记
        for (int i = head[u]; i; i = e[i].next)//与spfa几乎一样的遍历边
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w)//几乎一样的寻找最优解
            {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v])
                {
                    q.push((node){dis[v], v});//这里
                }
            }
        }
    }
    return;
}
int main()
{
    cin >> n >> m >> s;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}