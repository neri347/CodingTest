/// ����
/// https://www.acmicpc.net/problem/14890
/// ���� �� ��ġ���� �ٸ� ���θ� �� �� ����.
/// ���� ���� Ȯ��
/// ���� ���̸�ŭ �� Ȯ�� �ʿ�
#include <iostream>
#include <vector>
using namespace std;

int N, L;
int board[100][100];

bool CheckRoad(int x, int y, int height, int dir, vector<bool>& isSloped)
{
	if (dir == 1) // �������� üũ
	{
		int ny = y - 1;
		int count = 1;
		while (ny >= 0 && ny < N && !isSloped[ny] && board[x][ny] == height && count < L)
		{
			isSloped[ny] = true;
			--ny;
			++count;
		}
		if (count >= L)
		{
			isSloped[y] = true;
			return true;
		}
	}
	else if (dir == 2) // ���������� üũ
	{
		int ny = y + 1;
		int count = 1;
		while (ny >= 0 && ny < N && !isSloped[ny] && board[x][ny] == height && count < L)
		{
			isSloped[ny] = true;
			++ny;
			++count;
		}
		if (count >= L)
		{
			isSloped[y] = true;
			return true;
		}
	}
	else if (dir == 3) // ������ üũ
	{
		int nx = x + 1;
		int count = 1;
		while (nx >= 0 && nx < N && !isSloped[nx] && board[nx][y] == height && count < L)
		{
			isSloped[nx] = true;
			++nx;
			++count;
		}
		if (count >= L)
		{
			isSloped[x] = true;
			return true;
		}
	}
	else // ���� üũ
	{
		int nx = x - 1;
		int count = 1;
		while (nx >= 0 && nx < N && !isSloped[nx] && board[nx][y] == height && count < L)
		{
			isSloped[nx] = true;
			--nx;
			++count;
		}
		if (count >= L)
		{
			isSloped[x] = true;
			return true;
		}
	}
	return false;
}

int main()
{
	int answer = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;
			board[i][j] = n;
		}
	}

	// ���� ��
	for (int i = 0; i < N; i++)
	{
		vector<bool> isSloped(N, false); // ���� ����ִ���
		bool flag = true;
		for (int j = 1; j < N; j++)
		{
			if (isSloped[j])
			{
				continue;
			}
			if (board[i][j - 1] != board[i][j])
			{
				// ������ 1�̸� ���� �� �� �ִ�.
				// ���δ� ���� ���� ���.
				if (board[i][j - 1] - board[i][j] == -1) // ���� ĭ�� �� ���� ���
				{
					if (isSloped[j - 1] || !CheckRoad(i, j - 1, board[i][j - 1], 1, isSloped))
					{
						flag = false;
						break;
					}
				}
				else if (board[i][j - 1] - board[i][j] == 1) // ���� ĭ�� �� ���� ���
				{
					if (isSloped[j] || !CheckRoad(i, j, board[i][j], 2, isSloped))
					{
						flag = false;
						break;
					}
				}
				else // ���� �� 2 �̻��̸� ���� �� �� ����.
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			++answer;
		}
	}

	// ���� ��
	for (int i = 0; i < N; i++)
	{
		vector<bool> isSloped(N, false);
		bool flag = true;
		for (int j = 1; j < N; j++)
		{
			if (isSloped[j])
			{
				continue;
			}

			if (board[j - 1][i] != board[j][i])
			{
				// ������ 1�̸� ���� �� �� �ִ�.
				if (board[j - 1][i] - board[j][i] == -1)
				{
					if (isSloped[j - 1] || !CheckRoad(j - 1, i, board[j - 1][i], 4, isSloped))
					{
						flag = false;
						break;
					}
				}
				else if (board[j - 1][i] - board[j][i] == 1)
				{
					if (isSloped[j] || !CheckRoad(j, i, board[j][i], 3, isSloped))
					{
						flag = false;
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}
		}

		if (flag)
		{
			++answer;
		}
	}

	cout << answer;
	return 0;
}