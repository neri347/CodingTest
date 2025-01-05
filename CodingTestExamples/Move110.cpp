/// 110 �ű��
/// https://school.programmers.co.kr/learn/courses/30/lessons/77886
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(vector<string> s) {
	vector<string> answer;
	stack<char> stk;

	for (int i = 0; i < s.size(); ++i)
	{
		// "110"�� ã�� �� ���� ������ �ݺ�
		string str = s[i];
		int count = 0;
		for (int k = 0; k < str.size(); ++k)
		{
			char ch = str[k];
			stk.push(ch);
			if (ch == '0')
			{
				if (stk.size() >= 3)
				{
					char third = stk.top();
					stk.pop();
					char second = stk.top();
					stk.pop();
					char first = stk.top();
					stk.pop();
					if (first == '1' && second == '1')
					{
						++count;
					}
					else
					{
						stk.push(first);
						stk.push(second);
						stk.push(third);
					}
				}
			}
		}

		string stkStr = "";
		int lastZeroIdx = -1;
		while (!stk.empty())
		{
			char ch = stk.top();
			stk.pop();
			stkStr.insert(0, 1, ch);
			if (lastZeroIdx == -1 && ch == '0')
			{
				lastZeroIdx = stk.size();
			}
		}

		// str�� ������ 0 �ڿ� 110�� �����Ѵ�. ã�� 110 ������ŭ �ݺ�

		for (int j = 0; j < count; ++j)
		{
			stkStr.insert(lastZeroIdx + 1, "110");
		}
		answer.push_back(stkStr);
	}

	return answer;
}

int main()
{

	return 0;
}