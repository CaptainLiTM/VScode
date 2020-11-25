#include <iostream>
#define MAXN 200010
using namespace std;
int n, m, a[MAXN], tree[MAXN << 2], tag[MAXN << 2];
inline int left_son(int root) { return root << 1; }
inline int right_son(int root) { return root << 1 | 1; }
inline void push_up(int root)
{
    tree[root] = tree[left_son(root)] + tree[right_son(root)];
    return;
}
void build(int root, int left, int right)
{
    tag[root] = 0;
    if (left == right)
    {
        tree[root] = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(left_son(root), left, mid);
    build(right_son(root), mid + 1, right);
    push_up(root);
    return;
}
inline void lazy(int root, int left, int right, int k)
{
    tag[root] += k;
    tree[root] += k * (right - left + 1);
    return;
}
inline void push_down(int root, int left, int right)
{
    int mid = (left + right) >> 1;
    lazy(left_son(root), left, mid, tag[root]);
    lazy(right_son(root), mid + 1, right, tag[root]);
    tag[root] = 0;
    return;
}
void single_point_modifition()
{
    
}
int main()
{
    ios::sync_with_stdio(false);
    char b;
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> b;
        switch (b)
        {
        case 'C':
            cin >> x >> y;
            break;

        case 'P':

            break;
        }
    }
}