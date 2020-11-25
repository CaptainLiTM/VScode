#include <iostream>
#define MAXN 50010
using namespace std;
int n, m, u, v, w;
struct edge
{
    int next, to, w;
}e[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
    }
    system("pause");
    return 0;
}