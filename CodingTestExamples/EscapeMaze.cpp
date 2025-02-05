/// 미로 탈출
/// https://school.programmers.co.kr/learn/courses/30/lessons/159993
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isVisited[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int solution(vector<string> maps) {
	int answer = 0;
	int maxX = maps.size();
	int maxY = maps[0].size();

	pair<int, int> curPos;
	pair<int, int> lever;
	pair<int, int> end;
	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[i].size(); j++)
		{
			if (maps[i][j] == 'S')
			{
				curPos = { i, j };
			}
			else if (maps[i][j] == 'E')
			{
				end = { i, j };
			}
			else if (maps[i][j] == 'L')
			{
				lever = { i, j };
			}
		}
	}

	queue<pair<pair<int, int>, int>> q; // x,y,second
	q.push({ curPos, 0 });


	// 레버까지
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int s = q.front().second;

		// 레버 지점에 도착했다면 종료
		if (x == lever.first && y == lever.second)
		{
			answer = s;
			curPos = { x, y };
			break;
		}

		q.pop();

		if (isVisited[x][y])
		{
			continue;
		}
		isVisited[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < maxX && ny >= 0 && ny < maxY && maps[nx][ny] != 'X')
			{
				q.push({ {nx, ny}, s + 1 });
			}
		}
	}

	// curPos가 레버위치랑 다르다면 레버에 도달하지 못함 -> 미로 빠져나갈 수 없다
	if (curPos != lever)
	{
		return -1;
	}

	q = queue<pair<pair<int, int>, int>>();
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			isVisited[i][j] = false;
		}
	}
	q.push({ {lever.first, lever.second}, answer });

	// 도착점까지
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int s = q.front().second;

		// 도착 지점에 도착했다면 종료
		if (x == end.first && y == end.second)
		{
			answer = s;
			curPos = end;
			break;
		}

		q.pop();

		if (isVisited[x][y])
		{
			continue;
		}
		isVisited[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < maxX && ny >= 0 && ny < maxY && maps[nx][ny] != 'X')
			{
				q.push({ {nx, ny}, s + 1 });
			}
		}
	}

	return (curPos == end) ? answer : -1;
}

int main()
{
	vector<string> maps = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" };
	cout << solution(maps);
	return 0;
}