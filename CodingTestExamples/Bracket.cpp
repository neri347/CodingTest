/// 괄호
/// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		stack<char> stk;
		// 각 케이스마다 입력
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '(')
			{
				stk.push(str[j]);
			}
			else if (str[j] == ')')
			{
				if (!stk.empty() && stk.top() == '(')
				{
					stk.pop();
				}
				else
				{
					stk.push(str[j]);
					break;
				}
			}
		}
		stk.empty() ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}