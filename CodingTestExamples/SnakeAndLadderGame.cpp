/// 뱀과 사다리 게임
/// https://www.acmicpc.net/problem/16928
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int board[101];
bool isVisited[101];

int main()
{
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		board[from] = to;
	}
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		board[from] = to;
	}

	int answer = 0;
	queue<pair<int, int>> q; // pos, count
	q.push({ 1, 0 });
	isVisited[1] = true;

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

		for (int i = 6; i >= 1; i--)
		{
			int next = board[pos + i];
			if (next == 0) // 뱀이나 사다리가 있는 자리
			{
				next = pos + i;				
			}
			if (next <= 100 && !isVisited[next])
			{
				isVisited[next] = true;
				q.push({ next, count + 1 });
			}
		}
	}
	cout << answer;
	return 0;
}