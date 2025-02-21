/// ��ȣ�� ��
/// https://www.acmicpc.net/problem/2504
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	string input;
	cin >> input;

	int answer = 0;
	int temp = 1;
	stack<char> stk;
	
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(') //�ϴ� ���۰�ȣ�� ������ 2�� ����
		{
			temp *= 2;
			stk.push('(');
		}
		else if (input[i] == '[') //�ϴ� ���۰�ȣ�� ������ 3�� ����
		{
			temp *= 3;
			stk.push('[');
		}
		else if (input[i] == ')')
		{
			//�߸��� ��ȣ ������ ���
			if (stk.empty() || stk.top() != '(')
			{
				answer = 0;
				break;
			}
			if (input[i - 1] == '(')
			{
				answer += temp;
			}
			temp /= 2;
			stk.pop();
		}
		else if (input[i] == ']')
		{
			if (stk.empty() || stk.top() != '[')
			{
				//�߸��� ��ȣ ������ ���
				answer = 0;
				break;
			}
			if (input[i - 1] == '[')
			{
				answer += temp;
			}
			temp /= 3;
			stk.pop();
		}
	}

	if (!stk.empty())
	{
		answer = 0;
	}

	cout << answer;
	return 0;
}