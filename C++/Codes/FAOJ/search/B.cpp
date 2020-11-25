#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 110
using namespace std;
struct stu
{
	string name;
	int escore, cscore, papers, money;
	char leader, west;
}s[MAXN];
inline int academician_money(stu k)
{
	if (k.escore > 80 && k.papers >= 1)
		return 8000;
	return 0;
}
inline int Mayfourth_money(stu k)
{
	if (k.escore > 85 && k.cscore > 80)
		return 4000;
	return 0;
}
inline int high_score_money(stu k)
{
	if (k.escore > 90)
		return 2000;
	return 0;
}
inline int west_money(stu k)
{
	if (k.escore > 85 && k.west == 'Y')
		return 1000;
	return 0;
}
inline int class_money(stu k)
{
	if (k.cscore > 80 && k.leader == 'Y')
		return 850;
	return 0;
}
inline bool cmp (stu x1, stu x2)
{
		return x1.money > x2.money;
}
int main()
{
	int n;
	cin >> n;
	int all = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].name >> s[i].escore >> s[i].cscore >> s[i].leader >> s[i].west >> s[i].papers;
		s[i].money = academician_money(s[i]) + Mayfourth_money(s[i]) + high_score_money(s[i]) + west_money(s[i]) + class_money(s[i]);
		all += s[i].money;
	}
	stable_sort(s + 1, s + n + 1, cmp);
	cout << s[1].name << endl << s[1].money << endl << all << endl;
	//system("pause");
	return 0;
}
