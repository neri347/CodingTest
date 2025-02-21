/// 괄호의 값
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
		if (input[i] == '(') //일단 시작괄호는 무조건 2를 곱함
		{
			temp *= 2;
			stk.push('(');
		}
		else if (input[i] == '[') //일단 시작괄호는 무조건 3을 곱함
		{
			temp *= 3;
			stk.push('[');
		}
		else if (input[i] == ')')
		{
			//잘못된 괄호 맺음인 경우
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
				//잘못된 괄호 맺음인 경우
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