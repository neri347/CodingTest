/// ¾Ë°í½ºÆÌ
/// https://www.acmicpc.net/problem/1261
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int board[100][100];
bool isVisited[100][100];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

int main()
{
	int N, M;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			char ch = str[j];
			int v = ch - '0';
			board[i][j] = v;
		}
	}

	deque<pair<pair<int, int>, int>> dq;
	dq.push_back({ { 0, 0 }, 0 });
	isVisited[0][0] = true;

	while (!dq.empty())
	{
		int x = dq.front().first.first;
		int y = dq.front().first.second;
		int count = dq.front().second;
		dq.pop_front();

		if (x == N - 1 && y == M - 1)
		{
			cout << count;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !isVisited[nx][ny])
			{
				isVisited[nx][ny] = true;
				if (board[nx][ny] == 0)
				{
					dq.push_front({ {nx, ny}, count });
				}
				else
				{
					dq.push_back({ {nx, ny}, count + 1 });
				}
			}
		}
	}

	return 0;
}