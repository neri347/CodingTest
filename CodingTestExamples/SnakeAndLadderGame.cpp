/// 뱀과 사다리 게임
/// https://www.acmicpc.net/problem/16928
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> connected(101, -1);

	// 사다리로 연결된 칸
	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		connected[from] = to;
	}
	 
	// 뱀으로 연결된 칸
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		connected[from] = to;
	}

	queue<pair<int, int>> q;
	vector<bool> isVisited(101, false);
	q.push({ 1, 0 });
	isVisited[1] = true;
	int answer = 0;

	while (!q.empty())
	{
		int pos = q.front().first;
		int count = q.front().second;
		q.pop();

		if (pos == 100)
		{
			answer = count;
			break;
		}

		// 사다리나 뱀이 있다면 연결된 곳으로 이동
		if (connected[pos] != -1)
		{
			pos = connected[pos];
			isVisited[pos] = true;
		}

		if (pos + 6 <= 100 && !isVisited[pos + 6])
		{
			isVisited[pos + 6] = true;
			q.push({ pos + 6, count + 1 });
		}
		if (pos + 5 <= 100 && !isVisited[pos + 5])
		{
			isVisited[pos + 5] = true;
			q.push({ pos + 5, count + 1 });
		}
		if (pos + 4 <= 100 && !isVisited[pos + 4])
		{
			isVisited[pos + 4] = true;
			q.push({ pos + 4, count + 1 });
		}
		if (pos + 3 <= 100 && !isVisited[pos + 3])
		{
			isVisited[pos + 3] = true;
			q.push({ pos + 3, count + 1 });
		}
		if (pos + 2 <= 100 && !isVisited[pos + 2])
		{
			isVisited[pos + 2] = true;
			q.push({ pos + 2, count + 1 });
		}
		if (pos + 1 <= 100 && !isVisited[pos + 1])
		{
			isVisited[pos + 1] = true;
			q.push({ pos + 1, count + 1 });
		}
	}
	cout << answer;
	return 0;
}