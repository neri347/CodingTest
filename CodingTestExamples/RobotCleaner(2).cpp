/// �κ� û�ұ�
/// https://www.acmicpc.net/problem/4991
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 999999999;

int w, h;

char board[20][20];
int dist[20][20];
int startToTrash[10];
int trashToTrash[10][10];

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

// ���������κ��� �Ÿ� ���ϱ�
void BFS(int x, int y)
{
	fill(&dist[0][0], &dist[0][0] + 20 * 20, MAX);
	queue<pair<int, int>> q;
	q.push({ x, y });
	dist[x][y] = 0;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int count = dist[cx][cy];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] != 'x' && dist[nx][ny] > count + 1)
			{
				dist[nx][ny] = count + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	while (true)
	{
		cin >> w >> h;
		if (w == 0)
		{
			break;
		}

		int sx, sy;
		vector<pair<int, int>> dirtyPoint;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '*')
				{
					dirtyPoint.push_back({ i, j });
				}
				else if (board[i][j] == 'o')
				{
					sx = i;
					sy = j;
				}
			}
		}

		fill(&trashToTrash[0][0], &trashToTrash[0][0] + 10 * 10, 0);

		// ���������� �ٸ� ������ ĭ������ �Ÿ� ���ϱ�
		BFS(sx, sy);
		for (int i = 0; i < dirtyPoint.size(); i++)
		{
			startToTrash[i] = dist[dirtyPoint[i].first][dirtyPoint[i].second];
		}

		// ������ ĭ���κ��� �ٸ� ������ ĭ������ �Ÿ� ���ϱ�
		vector<int> trashNum;
		for (int i = 0; i < dirtyPoint.size(); i++)
		{
			BFS(dirtyPoint[i].first, dirtyPoint[i].second);
			trashNum.push_back(i);
			for (int j = 0; j < dirtyPoint.size(); j++)
			{
				if (i == j) continue;
				trashToTrash[i][j] = dist[dirtyPoint[j].first][dirtyPoint[j].second];
			}
		}

		// ���������κ��� ������ ������ ĭ���� ������, �׷κ��� ������ ĭ ��� ġ������ �� �� �ּ� ����� ã�´�.
		int answer = MAX;
		do 
		{
			int sum = startToTrash[trashNum[0]];
			bool flag = true;
			for (int i = 0; i < trashNum.size() - 1; i++)
			{
				// ������ �� ���� ������ ĭ�� ����
				if (trashToTrash[trashNum[i]][trashNum[i + 1]] == MAX)
				{
					flag = false;
					break;
				}
				sum += trashToTrash[trashNum[i]][trashNum[i + 1]];
			}
			if (!flag)
			{
				break;
			}
			answer = min(answer, sum);
		} while (next_permutation(trashNum.begin(), trashNum.end()));

		answer == MAX ? cout << -1 : cout << answer;
		cout << '\n';
	}
	return 0;
}