/// ¼û¹Ù²ÀÁú 2
/// https://www.acmicpc.net/problem/12851
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int answer = 0;

	queue<pair<int, int>> q; // pos, time
	vector<int> times(100001, INT_MAX);
	q.push({ N, 0 });
	times[N] = 0;

	while (!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (pos == K)
		{
			++answer;
			continue;
		}

		if (pos - 1 >= 0 && pos - 1 <= 100000)
		{
			if (time + 1 <= times[pos - 1])
			{
				times[pos - 1] = time + 1;
				q.push({ pos - 1, time + 1 });
			}
		}

		if (pos + 1 <= 100000 && pos + 1 >= 0)
		{
			if (time + 1 <= times[pos + 1])
			{
				times[pos + 1] = time + 1;
				q.push({ pos + 1, time + 1 });
			}
		}

		if (2 * pos >= 0 && 2 * pos <= 100000)
		{
			if (time + 1 <= times[2 * pos])
			{
				times[2 * pos] = time + 1;
				q.push({ 2 * pos, time + 1 });
			}
		}
	}

	cout << times[K] << '\n' << answer;
	return 0;
}