#include <iostream>
#include <unordered_set>//STL“无序set容器”，不会像set一样排序，各个元素的值互不相等，其底层采用哈希表存储
#include <string>           
#define MAXN 10010
using namespace std;
unordered_set<string> us;
string m;
int n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)//真不错，STL哈希真不错
    {
        cin >> m;
        us.insert(m);
    }
    cout << us.size() << endl;//快乐
    system("pause");//注意注释这行，而且提交时用c++11编译
    return 0;
}