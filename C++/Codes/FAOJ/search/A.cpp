#include <iostream>
using namespace std;
int main()
{
	int use, month = 1, now = 0, save = 0;
	while (cin >> use)
	{
		int b = now + 300 - use;
		if (b < 0)
		{
			cout << -month << endl;
			return 0;
		}
		while (b >= 100)
		{
			save += 100;
			b -= 100;
		}
		now = b;
		month++;
	}
	cout << now + save*1.2 << endl;
	return 0;
}
