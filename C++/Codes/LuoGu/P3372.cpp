#include <iostream>
#define MAXN (int)1e5 + 10
using namespace std;
long long n, ans[MAXN << 2], a[MAXN], tag[MAXN << 2];
inline long long left_son(long long root) { return root << 1; }
inline long long right_son(long long root) { return root << 1 | 1; }
inline void push_up(long long root)
{
    ans[root] = ans[left_son(root)] + ans[right_son(root)];
    return;
}
void build(long long root, long long left, long long right)
{
    tag[root] = 0;
    if (left == right)
    {
        ans[root] = a[left];
        return;
    }
    long long mid = (left + right) >> 1;
    build(left_son(root), left, mid);
    build(right_son(root), mid + 1, right);
    push_up(root);
    return;
}
inline void lazy(long long root, long long left, long long right, long long k)
{
    tag[root] += k;
    ans[root] += k * (right - left + 1);
    return;
}
inline void push_down(long long root, long long left, long long right)
{
    long long mid = (left + right) >> 1;
    lazy(left_son(root), left, mid, tag[root]);
    lazy(right_son(root), mid + 1, right, tag[root]);
    tag[root] = 0;
    return;
}
void interval_add(long long now_left, long long now_right, long long left, long long right, long long root, long long k)
{
    if (now_left <= left && now_right >= right)
    {
        lazy(root, left, right, k);
        return;
    }
    push_down(root, left, right);
    long long mid = (left + right) >> 1;
    if (now_left <= mid)
        interval_add(now_left, now_right, left, mid, left_son(root), k);
    if (now_right > mid)
        interval_add(now_left, now_right, mid + 1, right, right_son(root), k);
    push_up(root);
    return;
}
long long interval_query_sum(long long now_left, long long now_right, long long left, long long right, long long root)
{
    long long res = 0;
    if (now_left <= left && now_right >= right)
        return ans[root];
    long long mid = (left + right) >> 1;
    push_down(root, left, right);
    if (now_left <= mid)
        res += interval_query_sum(now_left, now_right, left, mid, left_son(root));
    if (now_right > mid)
        res += interval_query_sum(now_left, now_right, mid + 1, right, right_son(root));
    return res;
}
int main()
{
    long long n, m, b, c, d, e;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n); 
    for (long long i = 1; i <= m; i++)
    {
        cin >> e;
        switch (e)
        {
        case 1:
            cin >> b >> c >> d;
            interval_add(b, c, 1, n, 1, d);
            break;
        case 2:
            cin >> b >> c;
            cout << interval_query_sum(b, c, 1, n, 1) << endl;
            break;
        }
    }
    system("pause");
    return 0;
}