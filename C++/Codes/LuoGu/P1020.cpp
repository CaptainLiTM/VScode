#include <iostream>
#include <algorithm>
#define MAXN 100001
using namespace std;
int a[MAXN], n = 0, b[MAXN], c[MAXN];
int main()
{
    while (cin >> a[++n])
        ;
    n--;
    b[1] = a[1];
    c[1] = a[1];
    int sb = 1, sc = 1;
    for (int i = 2; i <= n; i++)
    {
        if (b[sb] >= a[i])
        {
            b[++sb] = a[i];
        }
        else
        {
            int p = upper_bound(b + 1, b + 1 + sb, a[i], greater<int>()) - b;
            b[p] = a[i];
        }
        if (c[sc] < a[i])
        {
            c[++sc] = a[i];
        }
        else
        {
            int k = lower_bound(c + 1, c + 1 + sc, a[i]) - c;
            c[k] = a[i];
        }
    }
    cout << sb << " " << sc << endl;
}