/// 수레 움직이기
/// https://school.programmers.co.kr/learn/courses/30/lessons/250134
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos
{
	int x_red;
	int y_red;
	int x_blue;
	int y_blue;
	int count; // 턴 수
};

int MAX = 10000000;
int N, M;
pair<int, int> end_red;
pair<int, int> end_blue;
vector<vector<bool>> isVisited_red;
vector<vector<bool>> isVisited_blue;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

int DFS(Pos pos, const vector<vector<int>>& maze)
{
	// 두 개 수레 모두 도착했다면 종료
	if (pos.x_red == end_red.first && pos.y_red == end_red.second &&
		pos.x_blue == end_blue.first && pos.y_blue == end_blue.second)
	{
		return pos.count;
	}

	int ret = MAX;

	for (int i = 0; i < 4; i++)
	{
		// 빨간 수레 움직이기
		int cx_red = pos.x_red;
		int cy_red = pos.y_red;
		
		// 도착점에 있으면 움직이지 않는다.
		if (cx_red != end_red.first || cy_red != end_red.second)
		{
			// 움직일 수 있는 위치로 움직인다.
			int nx_red = cx_red + dx[i];
			int ny_red = cy_red + dy[i];

			if (nx_red >= 0 && nx_red < N && ny_red >= 0 && ny_red < M &&
				!isVisited_red[nx_red][ny_red] && maze[nx_red][ny_red] != 5)
			{
				cx_red += dx[i];
				cy_red += dy[i];
			}
			else
			{
				continue;
			}
		}

		// 파란 수레 움직이기
		for (int j = 0; j < 4; j++)
		{
			int cx_blue = pos.x_blue;
			int cy_blue = pos.y_blue;
			// 도착점에 있으면 움직이지 않는다.
			if (cx_blue != end_blue.first || cy_blue != end_blue.second)
			{
				int nx_blue = cx_blue + dx[j];
				int ny_blue = cy_blue + dy[j];

				if (nx_blue >= 0 && nx_blue < N && ny_blue >= 0 && ny_blue < M &&
					!isVisited_blue[nx_blue][ny_blue] && maze[nx_blue][ny_blue] != 5)
				{
					cx_blue += dx[j];
					cy_blue += dy[j];
				}
				else
				{
					continue;
				}
			}
			// 움직인 자리에 다른 수레가 있는지 체크
			if (cx_red == cx_blue && cy_red == cy_blue)
			{
				continue;
			}
			// 수레끼리 스위칭 되었는지 체크
			// 빨간 수레가 옮긴 자리가 파란 수레가 전에 있던 위치이고,
			// 파란 수레가 옮긴 자리가 빨간 수레가 전에 있던 위치라면 스위칭
			if (cx_red == pos.x_blue && cy_red == pos.y_blue &&
				cx_blue == pos.x_red && cy_blue == pos.y_red)
			{
				continue;
			}

			isVisited_red[cx_red][cy_red] = true;
			isVisited_blue[cx_blue][cy_blue] = true;

			ret = min(ret, DFS({ cx_red, cy_red, cx_blue, cy_blue, pos.count + 1 }, maze));

			isVisited_red[cx_red][cy_red] = false;
			isVisited_blue[cx_blue][cy_blue] = false;
		}
	}

	return ret;
}

int solution(vector<vector<int>> maze) {
	N = maze.size();
	M = maze[0].size();
	isVisited_red.assign(N, vector<bool>(M, false));
	isVisited_blue.assign(N, vector<bool>(M, false));
	pair<int, int> start_red;
	pair<int, int> start_blue;

	// 시작점, 도착점 저장
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			if (maze[i][j] == 1)
			{
				start_red = { i, j };
			}
			else if (maze[i][j] == 2)
			{
				start_blue = { i, j };
			}
			else if (maze[i][j] == 3)
			{
				end_red = { i, j };
			}
			else if (maze[i][j] == 4)
			{
				end_blue = { i, j };
			}
		}
	}

	isVisited_red[start_red.first][start_red.second] = true;
	isVisited_blue[start_blue.first][start_blue.second] = true;
	int answer = DFS({ start_red.first, start_red.second, start_blue.first, start_blue.second, 0 }, maze);
	return answer == MAX ? 0 : answer;
}

int main()
{
	vector<vector<int>> maze = { {1, 4} ,{0, 0},{2, 3} };
	cout << solution(maze);
	return 0;
}