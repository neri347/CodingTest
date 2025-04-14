/// 치킨 배달
/// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M;
int board[50][50];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickenJoints;
vector<pair<int, int>> survived;
vector<int> distances;
int answer = INT_MAX;

void CheckDistance()
{
	distances.assign(houses.size(), INT_MAX);
	for (int i = 0; i < survived.size(); i++)
	{
		int x = survived[i].first;
		int y = survived[i].second;
		for (int j = 0; j < houses.size(); j++)
		{
			int cx = houses[j].first;
			int cy = houses[j].second;
			int distance = abs(x - cx) + abs(y - cy);
			distances[j] = min(distances[j], distance);
		}
	}

	int total = 0;
	for (auto& d : distances)
	{
		total += d;
	}
	answer = min(answer, total);
}

void DFS(int last, int count)
{
	if (count == M)
	{
		CheckDistance();
		return;
	}
	for (int i = last + 1; i < chickenJoints.size(); i++)
	{
		survived.push_back(chickenJoints[i]);
		DFS(i, count + 1);
		survived.pop_back();
	}
}

int main()
{
	// 입력
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				houses.push_back({ i, j });
			}
			else if (board[i][j] == 2)
			{
				chickenJoints.push_back({ i, j });
			}
		}
	}
	DFS(-1, 0);
	cout << answer;
	return 0;
}