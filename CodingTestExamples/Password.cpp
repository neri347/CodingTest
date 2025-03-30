/// 비밀번호
/// https://www.acmicpc.net/contest/problem/1467/2
#include <iostream>
#include <vector>
using namespace std;

int answer;
int board[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void DFS(int x, int y, int count, vector<vector<bool>> isVisited)
{
	if (count == 9)
	{
		++answer;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && !isVisited[nx][ny])
		{
			isVisited[nx][ny] = true;
			DFS(nx, ny, count + 1, isVisited);
			isVisited[nx][ny] = false;
		}
	}
}

int main()
{
	int K;
	cin >> K;
	int x = (K - 1) / 3;
	int y = (K - 1) % 3;
	vector<vector<bool>> isVisited(3, vector<bool>(3, false));
	isVisited[x][y] = true;
	DFS(x, y, 1, isVisited);
	cout << answer;
	return 0;
}