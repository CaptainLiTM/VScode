#include <iostream>
#include <cstring>
using namespace std;
int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int b[4];
int ans;
inline bool check(int a, int b, int c)
{
    if (a + b == c)
        return true;
    return false;
}
void match_sticks(int k, int n)
{
    if (k == 4)
    {
        if (check(b[1], b[2], b[3]) && n == 0)
            ans++;
        return;
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            if (n >= a[i])
            {
                b[k] = i;
                n -= a[i];
                match_sticks(k + 1, n);
                b[k] = -1;
                n += a[i];
            }
        }
    }
}
int main()
{
    memset(b, -1, sizeof(b));
    int n;
    cin >> n;
    n = n - 4;
    match_sticks(1, n);
    cout << ans << endl;
    system("pause");
    return 0;
}