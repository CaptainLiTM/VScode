#include <iostream>
using namespace std;
int n, x, ans, a[110];
bool f[110];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]] = true;
	}
	for (int i = 100; i >= 1 ; i--)
	{
		if (f[i] == true)
		{
			for (int j = i - 1; j >= 1; j--)
			{
				if (f[j] == true)
					f[i/j] = true;
			}
		}
	}
	for (int i = 1; i <= 100; i++)
	{
		if (f[i] == true)
			ans++;
	}
	cout << ans << endl;
	return 0;
}