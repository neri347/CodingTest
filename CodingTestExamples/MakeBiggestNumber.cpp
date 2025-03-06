/// ū �� �����
/// https://school.programmers.co.kr/learn/courses/30/lessons/42883#
/// �־��� string�� �� ���ڵ��� ó������ ���ÿ� ����
/// �� ���ڵ��� �����Ҷ� ������ top�� ���� ���ؼ� ũ�ٸ� top�� ����.
/// ������ �� �ִ� ��ŭ�� top���� �����ؾ� �Ѵ�.
/// ������ �� �ִ� Ƚ���� �ִ� ���� ����ؼ� top�� ���ڿ� ���ؼ� ������ ���ڰ� ũ�� top�� ����.
/// �� ���� ��, ������ ����� �־��� string�� ���̿��� k����ŭ �� ������� �۴ٸ� ������ ���ڸ� ���ÿ� �־��ش�.
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int v = k;
	stack<int> stk;
	for (char& ch : number)
	{
		int toInt = ch - '0';
		while (v > 0)
		{
			if (stk.empty())
			{
				break;
			}

			if (stk.top() < toInt)
			{
				stk.pop();
				--v;
			}
			else
			{
				break;
			}
		}

		if (stk.size() < number.size() - k)
		{
			stk.push(toInt);
		}
	}

	while (!stk.empty())
	{
		answer += stk.top() + '0';
		stk.pop();
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main()
{

	return 0;
}