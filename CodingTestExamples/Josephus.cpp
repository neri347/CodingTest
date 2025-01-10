/// 요세푸스 문제
/// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> answer;
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		q.push(i + 1);
	}

	while (!q.empty())
	{
		for (int i = 1; i < k; ++i)
		{
			int f = q.front();
			q.pop();
			q.push(f);
		}
		answer.push_back(q.front());
		q.pop();
	}
	
	cout << "<";
	for (int i = 0; i < answer.size(); ++i)
	{
		if (i == answer.size() - 1)
		{
			cout << answer[i];
		}
		else
		{
			cout << answer[i] << ", ";
		}
	}
	cout << ">";

	return 0;
}