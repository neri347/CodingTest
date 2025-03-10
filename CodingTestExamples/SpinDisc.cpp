/// ���� ������
/// https://www.acmicpc.net/problem/17822
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// i��° ȸ���Ҷ� ����ϴ� ������ xi, di, ki�̴�.
// ��ȣ�� xi�� ����� ������ di�������� kiĭ ȸ����Ų��. di�� 0�� ���� �ð� ����, 1�� ���� �ݽð� �����̴�.
// ���ǿ� ���� ���� ������, �����ϸ鼭 ���� ���� ���� ��� ã�´�.
// �׷��� ���� �ִ� ��쿡�� ���ǿ��� �����ϸ鼭 ���� ���� ��� �����.
// ���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.

int N, M, T;
int disc[50][50];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
bool flag;

void DFS(int x, int y, int value, vector<vector<bool>>& isVisited)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0)
		{
			ny = M - 1;
		}
		if (ny >= M)
		{
			ny = 0;
		}

		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !isVisited[nx][ny] && disc[nx][ny] == value)
		{
			flag = true;
			isVisited[nx][ny] = true;
			disc[x][y] = -1;
			disc[nx][ny] = -1;
			DFS(nx, ny, value, isVisited);
		}
	}
}

int main()
{
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int v;
			cin >> v;
			disc[i][j] = v;
		}
	}

	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		// ��ȣ�� x�� ����� ������ d�������� kĭ ȸ����Ų��
		for (int j = 0; j < N; j++)
		{
			if ((j + 1) % x == 0)
			{
				k %= M;

				deque<int> q;
				for (int m = 0; m < M; m++)
				{
					q.push_back(disc[j][m]);
				}

				if (d == 0) // �ð���� ȸ��
				{
					// �� ���� ��Ҹ� �� �տ�
					for (int r = 0; r < k; r++)
					{
						int value = q.back();
						q.pop_back();
						q.push_front(value);
					}
				}
				else // �ݽð���� ȸ��
				{
					// �� ���� ��Ҹ� �� �ڿ�
					for (int r = 0; r < k; r++)
					{
						int value = q.front();
						q.pop_front();
						q.push_back(value);
					}
				}

				for (int m = 0; m < M; m++)
				{
					int value = q.front();
					q.pop_front();
					disc[j][m] = value;
				}
			}
		}
		// ���ǿ� ���� ���� ������, �����ϸ鼭 ���� ���� ���� ��� ã�´�.
		// �׷��� ���� �ִ� ��쿡�� ���ǿ��� �����ϸ鼭 ���� ���� ��� �����.		
		flag = false;
		vector<vector<bool>> isVisited(50, vector<bool>(50, false));
		for (int j = 0; j < N; j++)
		{
			for (int m = 0; m < M; m++)
			{
				int value = disc[j][m];
				if (value == -1 || isVisited[j][m])
				{
					continue;
				}
				isVisited[j][m] = true;
				DFS(j, m, value, isVisited);
			}
		}

		if (!flag)
		{
			// ���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.
			float sum = 0;
			int count = 0;
			for (int j = 0; j < N; j++)
			{
				for (int m = 0; m < M; m++)
				{
					if (disc[j][m] != -1)
					{
						sum += disc[j][m];
						count++;
					}
				}
			}

			if (count != 0)
			{
				float avg = sum / count;
				for (int j = 0; j < N; j++)
				{
					for (int m = 0; m < M; m++)
					{
						if (disc[j][m] != -1)
						{
							if (disc[j][m] > avg)
							{
								disc[j][m]--;
							}
							else if (disc[j][m] < avg)
							{
								disc[j][m]++;
							}
						}
					}
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (disc[i][j] != -1)
			{
				sum += disc[i][j];
			}
		}
	}
	cout << sum;

	return 0;
}