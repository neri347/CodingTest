/// A -> B
/// https://www.acmicpc.net/problem/16953
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
	int answer = INT_MAX;
	long long A, B;
	cin >> A >> B;
	queue<pair<long long, int>> q;
	q.push({ A, 1 });
	while (!q.empty())
	{
		long long v = q.front().first;
		int count = q.front().second;
		q.pop();

		if (v > B)
		{
			continue;
		}

		if (v == B)
		{
			answer = min(answer, count);
			break;
		}

		// 2 ���ϱ�
		q.push({ v * 2, count + 1 });
		// 1�� ���� ���� �����ʿ� �߰��ϱ�
		q.push({ v * 10 + 1, count + 1 });
	}
	answer == INT_MAX ? cout << -1 : cout << answer;
	return 0;
}