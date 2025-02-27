/// 연구소 3
/// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int answer = INT_MAX;
int emptyCount;
int map[50][50];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
vector<pair<int, int>> virus;
vector<int> activated;

int ActivateVirus()
{
	queue<pair<int, int>> q;
	int time[50][50];
	memset(time, -1, sizeof(time));
	for (int i = 0; i < activated.size(); i++)
	{
		q.push(virus[activated[i]]);
		time[virus[activated[i]].first][virus[activated[i]].second] = 0;
	}

	int second = 0;
	int visitCount = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && time[nx][ny] == -1 && map[nx][ny] != 1)
			{
				time[nx][ny] = time[x][y] + 1;
				if (map[nx][ny] == 0)
				{
					++visitCount;
					second = time[nx][ny]; // 그 칸에 비활성화 바이러스가 있다면 시간에 반영하지 않는다.
				}
				q.push({ nx, ny });
			}
		}
	}

	// 벽 제외한 곳을 모두 방문했다면 모든 칸에 바이러스 퍼뜨리기 성공
	if (visitCount == emptyCount)
	{
		return second;
	}

	return INT_MAX;
}

void ChooseVirus(int count, int index)
{
	if (count == M)
	{
		answer = min(answer, ActivateVirus());
		return;
	}

	for (int i = index; i < virus.size(); i++)
	{
		activated.push_back(i);
		ChooseVirus(count + 1, i + 1);
		activated.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int v;
			cin >> v;
			map[i][j] = v;
			if (v == 0)
			{
				++emptyCount;
			}
			else if (v == 2)
			{
				virus.push_back({ i, j });
			}
		}
	}
	ChooseVirus(0, 0);
	answer == INT_MAX ? cout << -1 : cout << answer;

	return 0;
}