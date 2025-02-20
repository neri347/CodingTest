/// ���� �����̱�
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
	int count; // �� ��
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
	// �� �� ���� ��� �����ߴٸ� ����
	if (pos.x_red == end_red.first && pos.y_red == end_red.second &&
		pos.x_blue == end_blue.first && pos.y_blue == end_blue.second)
	{
		return pos.count;
	}

	int ret = MAX;

	for (int i = 0; i < 4; i++)
	{
		// ���� ���� �����̱�
		int cx_red = pos.x_red;
		int cy_red = pos.y_red;
		
		// �������� ������ �������� �ʴ´�.
		if (cx_red != end_red.first || cy_red != end_red.second)
		{
			// ������ �� �ִ� ��ġ�� �����δ�.
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

		// �Ķ� ���� �����̱�
		for (int j = 0; j < 4; j++)
		{
			int cx_blue = pos.x_blue;
			int cy_blue = pos.y_blue;
			// �������� ������ �������� �ʴ´�.
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
			// ������ �ڸ��� �ٸ� ������ �ִ��� üũ
			if (cx_red == cx_blue && cy_red == cy_blue)
			{
				continue;
			}
			// �������� ����Ī �Ǿ����� üũ
			// ���� ������ �ű� �ڸ��� �Ķ� ������ ���� �ִ� ��ġ�̰�,
			// �Ķ� ������ �ű� �ڸ��� ���� ������ ���� �ִ� ��ġ��� ����Ī
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

	// ������, ������ ����
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