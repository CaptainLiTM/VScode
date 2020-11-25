#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <stack>
#define MAXT 110
using namespace std;
int t;
bool check (int ans, string o)
{
    stringstream o1;
    string o2;
    if (ans == 0)
        o2 = "O(1)";
    else
    {
        o1 << "O(n^" << ans << ")";
        o1 >> o2;
    }
    if (o == o2)
        return true;
    return false;
}
void program_check(int l, string o)
{
    set<string> se;
    stack<string> st;
    string a, b, c, d;
    stringstream c1, d1;
    int c2, d2;
    int now = 0;//0:常数  1:n 2:n方  以此类推
    int ans = 0;
    int bl = false;
    for (int i = 1; i <= l; i++)
    {
        cin >> a;
        if (a == "F")
        {
            cin >> b >> c >> d;
            c1 << c;
            d1 << d;
            c1 >> c2;
            d1 >> d2;
            if (se.count(b))
            {
                cout << "ERR" << endl;
                return;
            }
            if (c == "n")
            {
                c = d = 1;
                bl = true;
            }
            if (c2 > d2 && c != "n" && d != "n")
            {
                bl = true;
            }
            se.insert(b);
            st.push(b);
            if (d == "n" && !bl)
                now++;
        }
        else if (a == "E")
        {
            if (bl)
                bl = false;
            if (!st.size())
            {
                cout << "ERR" << endl;
                return;
            }
            else
            {
                now--;
                se.erase(st.top());
                st.pop();
            }
        }
        ans = max(ans, now);
    }
    if(st.size())
    {
        cout << "ERR" << endl;
        return;
    }
    if (check(ans, o))
    {
        cout << "Yes" << endl;
        return;
    }
    else
    {
        cout << "No" << endl;
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    int l;
    string o1;
    for (int i = 1; i <= t; i++)
    {
        cin >> l >> o1;
        program_check(l, o1);
    }
    system("pause");
    return 0;
}