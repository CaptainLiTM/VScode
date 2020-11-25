#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans1, x, ans2;
vector<int> a, b, c, d;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a.push_back(x);
        b.push_back(x);
        c.push_back(x);
        d.push_back(x);
    }
    sort(b.begin(), b.end());
    sort(d.begin(), d.end());
    for (vector<int>::iterator ait = a.begin(), bit = b.begin(); ait != a.end(), bit != b.end(); ++ait, ++bit)
    {
        if (*ait != *bit)
        {
            vector<int>::iterator it = find(a.begin(), a.end(), *bit);
            iter_swap(it, ait);
            ans1 += *it + *ait;
        }
    }
    vector<int>::iterator it1 = find(c.begin());
    for (vector<int>::iterator cit = c.begin(); cit != c.end(); ++cit)
    {
        if (*cit != d.front())
        {
            vector<int>::iterator it = find(c.begin(), c.end(), d.front());
            iter_swap(it, cit);
            ans2 += *it + *cit;
        }
    }
    it1 = find(c.begin(), c.end(), d.front());
    iter_swap(it1, c.begin());
    ans2 -= (*it1 + c.front());
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;
    cout << ans1 << " " << ans2 << endl;
    system("pause");
    return 0;
}