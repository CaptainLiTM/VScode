#include <iostream>
#include <cstring>
using namespace std;
int n;
int x[15];
bool vx[15], vl[30], vr[30];
int ans = 0;
void queen(int k)
{
    if (k == n + 1)
    {
        ans++;
        if (ans <= 3)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (vx[i] == true && vl[k + i - 1] == true && vr[k - i + n] == true)
            {
                x[k] = i;
                vx[i] = false;
                vl[k + i - 1] = false;
                vr[k - i + n] = false;
                queen(k + 1);
                vr[k - i + n] = true;
                vl[k + i - 1] = true;
                vx[i] = true;
                x[k] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    memset(x, 0, sizeof(x));
    memset(vx, true, sizeof(vx));
    memset(vl, true, sizeof(vl));
    memset(vr, true, sizeof(vr));
    queen(1);
    cout << ans << endl;
    system("pause");
    return 0;
}