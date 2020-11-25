#include <iostream>
#define MAXN 200010
using namespace std;
int tree[MAXN << 2], a[MAXN], tag[MAXN << 2];
inline int left_son(int root) { return root >> 1; }
inline int right_son(int root) { return root >> 1 | 1; }
inline void push_up(int root)
{
    tree[root] = tree[left_son(root)] + tree[right_son(root)];
    return;
}
inline void build()
{
    for (m = 1; m < n; m <<= 1)
        ;
    for (int i = m + 1; i <= m + n; i++)
        cin >> tree[i];
    for (int i = m - 1; i; --i)
        push_up(i);
    return;
}
inline void single_point_modification(int pos, int v)
{
    pos += m;
    tree[pos] = v;
    for (pos >>= 1; pos; pos >>= 1)
        push_up(pos);
}
inline int interval_sum_query(int left, int right)
{
    int ans = 0;
    for (left += m - 1, right += m + 1; left ^ right ^ 1; left >>= 1, right >>= 1)
    {
        if (~left & 1)
            ans += tree[left ^ 1];
        if (right & 1)
            ans += tree[right ^ 1];
    }
    return ans;
}
int main()
{
    int n, m, x, y;
    char b;
    cin >> n >> m;
    
}