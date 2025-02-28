/// ���� ����ũ
/// https://www.acmicpc.net/problem/16235
/// ���ѽð��� 0.3�ʷ� ���� ������ 1/3�����̹Ƿ� ���ѽð��� �����ؾ� �Ѵ�.
/// ���ʿ��� ������ ���̰�, �˸��� �ڷᱸ���� ���������ν� �ذ��� �� �־���.
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M, K;
int board[10][10];
int fertilizer[10][10];
deque<int> trees[10][10];
int dx[8] = { 1,0,0,-1,1,1,-1,-1 };
int dy[8] = { 0,1,-1,0,1,-1,1,-1 };

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int v;
			cin >> v;
			board[i][j] = 5;
			fertilizer[i][j] = v;
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		int x, y, old;
		cin >> x >> y >> old;
		trees[x - 1][y - 1].push_back(old);
	}

	for (int i = 1; i <= K; i++)
	{
		// �� = ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�. 
		// �ϳ��� ĭ�� ���� ���� ������ �ִٸ�, ���̰� � �������� ����� �Դ´�. 
		// ����, ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����� ���� ���ϰ� ��� �״´�.
		// ���� - ���� ���� ������ ������� ���ϰ� �ȴ�. 
		// ������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�. �Ҽ��� �Ʒ��� ������.
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				auto iter = trees[r][c].begin();
				for (; iter != trees[r][c].end(); iter++)
				{
					if (*iter <= board[r][c]) // ����� ����ϴٸ� ����� �԰� ���� ����
					{
						board[r][c] -= *iter;
						*iter += 1;
					}
					else // ��� ������ ����. deque�� ���� ����� ����Ǿ� �ֱ� ������ ó�� �� �Դ� ���� ã���� �ڿ� �ִ� �����鵵 ��� �� �Դ´�.
					{
						break;
					}
				}

				// ��� �� ���� ������ ��� ����
				while (iter != trees[r][c].end())
				{
					board[r][c] += *iter / 2;
					iter = trees[r][c].erase(iter);
				}
			}
		}

		// ���� - ������ �����Ѵ�. �����ϴ� ������ ���̰� 5�� ����̾�� �ϸ�, 
		// ������ 8���� ĭ�� ���̰� 1�� ������ �����. 
		// �ܿ� - �� ĭ�� �߰��Ǵ� ����� ���� A[r][c]�̴�.
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				auto iter = trees[r][c].begin();
				for (; iter != trees[r][c].end(); iter++)
				{
					if (*iter % 5 == 0)
					{
						for (int k = 0; k < 8; k++)
						{
							int nx = r + dx[k];
							int ny = c + dy[k];
							if (nx >= 0 && nx < N && ny >= 0 && ny < N)
							{
								trees[nx][ny].push_front(1);
							}
						}
					}
				}
				board[r][c] += fertilizer[r][c];
			}
		}
	}

	int answer = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			answer += trees[r][c].size();
		}
	}

	cout << answer;
	return 0;
}