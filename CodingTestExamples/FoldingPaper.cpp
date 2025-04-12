#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<pair<int, int>>>> vec;
vector<vector<bool>> isVisited;

void Cut(int x, int y, vector<vector<int>>& paper)
{
	paper[x][y] = 0;
	for (auto& [nextX, nextY] : vec[x][y])
	{
		if (!isVisited[nextX][nextY])
		{
			isVisited[nextX][nextY] = true;
			Cut(nextX, nextY, paper);
		}
	}
}

vector<vector<int>> solution(vector<vector<int>> paper, vector<vector<int>> cut, vector<int> fold)
{
	int x = paper.size();
	int y = paper[0].size();
	vec.assign(x, vector<vector<pair<int, int>>>(y));
	isVisited.assign(x, vector<bool>(y, false));
	for (auto& dir : fold)
	{
		// 위로 접기
		if (dir == 0)
		{
			for (int i = 0; i < x / 2; i++)
			{
				for (int j = 0; j < y; j++)
				{
					vec[i][j].push_back({ x - 1 - i, j });
				}
			}
			x /= 2;
		}
		else // 왼쪽으로 접기
		{
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y / 2; j++)
				{
					vec[i][j].push_back({ i, y - 1 - j });
				}
			}
			y /= 2;
		}
	}

	for (auto& v : cut)
	{
		int curX = v[0] - 1;
		int curY = v[1] - 1;
		paper[curX][curY] = 0;
		isVisited[curX][curY] = true;
		Cut(curX, curY, paper);
	}
	return paper;
}

int main()
{
	vector<vector<int>> paper =
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
	};

	vector<vector<int>> cut = {
		{3, 4},
		{4, 3}
	};

	vector<int> fold = { 0, 1 };
	vector<vector<int>> answer = solution(paper, cut, fold);
	return 0;
}