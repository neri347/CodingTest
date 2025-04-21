/// 오등큰수
/// https://www.acmicpc.net/problem/17299
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int counts[1'000'001];

int main()
{
	int N;
	cin >> N;
	vector<int> vec;
	vector<int> answer(N);
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		vec.push_back(v);
		counts[v]++;
	}

	stack<int> stk; // index
	for (int i = 0; i < N; i++)
	{
		if (stk.empty())
		{
			stk.push(i);
		}
		else
		{
			while (!stk.empty())
			{
				int index = stk.top();
				if (counts[vec[index]] < counts[vec[i]])
				{
					answer[index] = vec[i];
					stk.pop();
				}
				else
				{
					break;
				}
			}
			stk.push(i);
		}
	}
	while (!stk.empty())
	{
		int index = stk.top();
		answer[index] = -1;
		stk.pop();
	}

	for (auto& e : answer)
	{
		cout << e << ' ';
	}

	return 0;
}