/// �� �μ��� �̵��ϱ�
/// https://www.acmicpc.net/problem/2206
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

struct Info
{
	int x;
	int y;
	int moveCount;
	int breakableCount;
};

int main()
{
	int answer = -1;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	//[x][y][0] : ���� �ѹ� �μ� ä �湮(���� Ƚ�� ����), [x][y][1] : ���� �μ��� ���� ä �湮(���� Ƚ�� ����)
	vector<vector<vector<bool>>> isVisited(N, vector<vector<bool>>(M, vector<bool>(2, false))); 
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			int v = str[j] - '0';
			board[i][j] = v;
		}
	}

	queue<Info> q;
	q.push({ 0, 0, 1, 1 });
	isVisited[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int moveCount = q.front().moveCount;
		int breakableCount = q.front().breakableCount;
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			answer = moveCount;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (board[nx][ny] == 0 && !isVisited[nx][ny][breakableCount])
				{
					isVisited[nx][ny][breakableCount] = true;
					q.push({ nx, ny, moveCount + 1, breakableCount });
				}
				else if (breakableCount == 1) // ���� �ְ� �μ� �� �ִ� ��ȸ�� �ִٸ� �μ���
				{
					isVisited[nx][ny][breakableCount - 1] = true;
					q.push({ nx, ny, moveCount + 1, breakableCount - 1 });
				}				
			}
		}
	}

	cout << answer;
	return 0;
}