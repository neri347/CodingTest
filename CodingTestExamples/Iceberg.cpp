/// ����
/// https://www.acmicpc.net/problem/2573
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int prev_board[300][300];
int board[300][300];
bool isVisited[300][300];

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !isVisited[nx][ny] && board[nx][ny])
		{
			isVisited[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}

int CountIcebergs()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] != 0 && !isVisited[i][j])
			{
				ret++;
				isVisited[i][j] = true;
				DFS(i, j);
			}
		}
	}
	return ret;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;
			board[i][j] = num;
		}
	}

	int answer = 0;
	while (true)
	{
		int iceCount = CountIcebergs();
		if (iceCount == 0)
		{
			answer = 0;
			break;
		}
		if (iceCount >= 2)
		{
			break;
		}
		++answer;
		// ���� �����س���
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{				
				prev_board[i][j] = board[i][j];
			}
		}

		// ���� ��� �� ó��
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				// ������ �ִ� �� 4���� üũ�ؼ� 0 �ִ� ������ŭ ���� ��´�.
				if (prev_board[i][j])
				{
					int count = 0;
					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						// ��ȿ�� �������� üũ
						if (nx >= 0 && nx < N && ny >= 0 && ny < M)
						{
							if (prev_board[nx][ny] == 0)
							{
								++count;
							}
						}
					}
					board[i][j] -= count;
					// ���� ���� 0 �����δ� �� ��������.
					if (board[i][j] < 0)
					{
						board[i][j] = 0;
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}