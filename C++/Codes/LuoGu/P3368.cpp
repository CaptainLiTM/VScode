#include <iostream>
#define MAX 500010
using namespace std;
long long n, m, tree[MAX];
inline long long lowbit(int k)
{
    return k & -k;
}
void change(long long x, long long k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
    return;
}
long long sum(long long x)
{
    long long ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    long long t = 0, a, b, i;
    cin >> n >> m;
    for(int i = 1; i <= n;i++)
    {
        cin >> a;
        change(i ,a - t);
        t = a;
    }
    while(m--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b >> i;
            change(a, i);
            change(b + 1, -i);
        }
        else if (t == 2)
        {
            cin >> a;
            cout << sum(a) << endl;
        }   
    }
    system("pause");
    return 0;
}