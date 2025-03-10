/// 원판 돌리기
/// https://www.acmicpc.net/problem/17822
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// i번째 회전할때 사용하는 변수는 xi, di, ki이다.
// 번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
// 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
// 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
// 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.

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
		// 번호가 x의 배수인 원판을 d방향으로 k칸 회전시킨다
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

				if (d == 0) // 시계방향 회전
				{
					// 맨 뒤의 요소를 맨 앞에
					for (int r = 0; r < k; r++)
					{
						int value = q.back();
						q.pop_back();
						q.push_front(value);
					}
				}
				else // 반시계방향 회전
				{
					// 맨 앞의 요소를 맨 뒤에
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
		// 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
		// 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.		
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
			// 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
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