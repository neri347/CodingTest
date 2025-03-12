/// IOIOI
/// https://www.acmicpc.net/problem/5525
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int size;
	cin >> size;
	string str;
	cin >> str;

	int answer = 0;
	stack<char> stk;
	for (char& ch : str)
	{
		if (stk.empty())
		{
			if (ch == 'I')
			{
				stk.push(ch);
			}
		}
		else
		{
			if (stk.top() == 'I')
			{
				if (ch == 'O')
				{
					stk.push(ch);
				}
				else
				{
					// stack clear
					while (!stk.empty())
					{
						stk.pop();
					}
					stk.push(ch);
				}
			}
			else
			{
				if (ch == 'I')
				{
					stk.push(ch);
				}
				else
				{
					// stack clear
					while (!stk.empty())
					{
						stk.pop();
					}
				}
			}

			if (stk.size() == 2 * N + 1)
			{
				++answer;
				stk.pop();
				stk.pop();
			}
		}
	}
	cout << answer;
	return 0;
}