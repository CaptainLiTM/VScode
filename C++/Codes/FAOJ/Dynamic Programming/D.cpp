#include <iostream>
#include <iomanip>
using namespace std;
int n;
int a[111];
vector<int> v;
double m = 100;
bool check;
int i;
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
    {
        if (check)
        {
            if (a[i + 1] < a[i] && i != n)
                continue;
            else
            {
                m /= a[i];
                m *= 100;
                check = false;
            }
        }
        else
        {
            if (a[i + 1] > a[i] && i != n || a[i + 1] == 0)
                continue;
            else
            {
                m /= 100;
                m *= a[i];
                check = true;
            }
        }
    }
    cout << fixed << setprecision(2) << m;
    system("pause");
    return 0;
}