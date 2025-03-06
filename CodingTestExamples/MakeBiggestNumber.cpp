/// 큰 수 만들기
/// https://school.programmers.co.kr/learn/courses/30/lessons/42883#
/// 주어진 string의 각 숫자들을 처음부터 스택에 저장
/// 각 숫자들을 저장할때 스택의 top의 값과 비교해서 크다면 top을 뺀다.
/// 제거할 수 있는 만큼만 top에서 제거해야 한다.
/// 제거할 수 있는 횟수가 있는 동안 계속해서 top의 숫자와 비교해서 지금의 숫자가 크면 top을 뺀다.
/// 다 빼고난 후, 스택의 사이즈가 주어진 string의 길이에서 k개만큼 뺀 사이즈보다 작다면 지금의 숫자를 스택에 넣어준다.
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