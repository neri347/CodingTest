/// ���ڿ� ����
/// https://www.acmicpc.net/problem/9935
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	string str;
	cin >> str;
	string explosion;
	cin >> explosion;
	int sz = explosion.size();
	reverse(explosion.begin(), explosion.end());

	stack<char> stk;
	for (auto& ch : str)
	{
		stk.push(ch);

		if (stk.size() >= sz)
		{
			int index = 0;
			stack<char> temp;
			while (index < sz && stk.top() == explosion[index])
			{
				char t = stk.top();
				stk.pop();
				temp.push(t);
				index++;
			}

			// index�� sz���� �۴ٴ� �� ���ÿ��� �� ���ڵ��� explosion�� ���� �ʴٴ� ���̴�.
			// �� ���ڵ��� �ٽ� ���ÿ� �־��ش�.
			if (index < sz)
			{
				while (!temp.empty())
				{
					char t = temp.top();
					temp.pop();
					stk.push(t);
				}
			}
		}
	}

	if (stk.empty())
	{
		cout << "FRULA";
	}
	else
	{
		string answer = "";
		while (!stk.empty())
		{
			char t = stk.top();
			stk.pop();
			answer += t;
		}
		reverse(answer.begin(), answer.end());
		cout << answer;
	}

	return 0;
}