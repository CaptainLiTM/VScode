#include <iostream>
using namespace std;
int n, a, b, c;
int main()
{
    cin >> n >> a;
    b = a;
    for (int i = 1; i < n; i++)
    {
        cin >> c;
        if (c > b)
            a = a + (c - b);
        b = c;
    }
    cout << a << endl;
    system("pause");
    return 0;
}