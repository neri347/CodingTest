/// û�ҳ� ���
/// https://www.acmicpc.net/problem/19236
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ������� ��, ��, ��, ��, ��, ��, ��, ��
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int answer;

void DFS(int x, int y, int score, vector<vector<pair<int, int>>> board)
{
	// �� ����� �Դ´�
	int dir = board[x][y].second;
	answer = max(answer, score);

	// ����� �̵�
	for (int n = 1; n <= 16; n++) // ����� ����
	{
		bool flag = false; // �ش� ����� �̵� �������� ����
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i][j].first == n)
				{
					int fishValue = board[i][j].first;
					int fishDir = board[i][j].second;
					for (int k = 0; k < 7; k++)
					{
						int nx = i + dx[fishDir];
						int ny = j + dy[fishDir];
						// ������ ��� ���̰� �� ���� ĭ���� �̵� �����ϴ�.
						if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && board[nx][ny].first != 17)
						{
							board[i][j].first = board[nx][ny].first;
							board[i][j].second = board[nx][ny].second;
							board[nx][ny].first = fishValue;
							board[nx][ny].second = fishDir;
							break;
						}
						else
						{
							fishDir++;
							if (fishDir > 7)
							{
								fishDir = 0;
							}
						}
					}

					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}

	// ��� �̵�
	for (int i = 1; i <= 3; i++)
	{
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		// ������ ��� ���̰� ����Ⱑ �ִ� ĭ���� �̵� �����ϴ�
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && board[nx][ny].first != 0)
		{
			int nv = board[nx][ny].first;
			board[nx][ny].first = 17;
			board[x][y].first = 0;

			DFS(nx, ny, score + nv, board);

			board[nx][ny].first = nv;
			board[x][y].first = 17;
		}
	}
}

int main()
{
	vector<vector<pair<int, int>>> board(4, vector<pair<int, int>>(4));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int value, dir;
			cin >> value >> dir;
			board[i][j] = { value, dir - 1 };
		}
	}

	int score = board[0][0].first;
	board[0][0].first = 17;
	DFS(0, 0, score, board);
	cout << answer;
	return 0;
}