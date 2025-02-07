/// 2048(Easy)
/// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int answer;

vector<vector<int>> Move(int dir, vector<vector<int>> map)
{
	if (dir == 0) // ����
	{
		for (int i = 0; i < N; i++) // ������ �� �پ�
		{
			stack<pair<int, bool>> stk;
			for (int j = 0; j < N; j++)
			{
				if (map[j][i] == 0)
				{
					continue;
				}

				if (!stk.empty() && map[j][i] == stk.top().first && !stk.top().second)
				{
					int val = stk.top().first * 2;
					stk.pop();
					stk.push({ val, true });
				}
				else
				{
					stk.push({ map[j][i], false });
				}
			}

			// ��ĭó��
			while (stk.size() < N)
			{
				stk.push({ 0, false });
			}

			// ������ ä���
			for (int j = N - 1; j >= 0; j--)
			{
				map[j][i] = stk.top().first;
				stk.pop();
			}
		}
	}
	else if (dir == 1) // �Ʒ���
	{
		for (int i = 0; i < N; i++) // ������ �� �پ�
		{
			stack<pair<int, bool>> stk;
			for (int j = N - 1; j >= 0; j--)
			{
				if (map[j][i] == 0)
				{
					continue;
				}

				if (!stk.empty() && map[j][i] == stk.top().first && !stk.top().second)
				{
					int val = stk.top().first * 2;
					stk.pop();
					stk.push({ val, true });
				}
				else
				{
					stk.push({ map[j][i], false });
				}
			}

			// ��ĭó��
			while (stk.size() < N)
			{
				stk.push({ 0, false });
			}

			// ������ ä���
			for (int j = 0; j < N; j++)
			{
				map[j][i] = stk.top().first;
				stk.pop();
			}
		}
	}
	else if (dir == 2) // ��������
	{
		for (int i = 0; i < N; i++) // ������ �� �پ�
		{
			stack<pair<int, bool>> stk;
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 0)
				{
					continue;
				}

				if (!stk.empty() && map[i][j] == stk.top().first && !stk.top().second)
				{
					int val = stk.top().first * 2;
					stk.pop();
					stk.push({ val, true });
				}
				else
				{
					stk.push({ map[i][j], false });
				}
			}

			// ��ĭó��
			while (stk.size() < N)
			{
				stk.push({ 0, false });
			}

			// ������ ä���
			for (int j = N - 1; j >= 0; j--)
			{
				map[i][j] = stk.top().first;
				stk.pop();
			}
		}
	}
	else // ����������
	{
		for (int i = 0; i < N; i++) // ������ �� �پ�
		{
			stack<pair<int, bool>> stk;
			for (int j = N - 1; j >= 0; j--)
			{
				if (map[i][j] == 0)
				{
					continue;
				}

				if (!stk.empty() && map[i][j] == stk.top().first && !stk.top().second)
				{
					int val = stk.top().first * 2;
					stk.pop();
					stk.push({ val, true });
				}
				else
				{
					stk.push({ map[i][j], false });
				}
			}

			// ��ĭó��
			while (stk.size() < N)
			{
				stk.push({ 0, false });
			}

			// ������ ä���
			for (int j = 0; j < N; j++)
			{
				map[i][j] = stk.top().first;
				stk.pop();
			}
		}
	}

	return map;
}

void BackTrack(int count, vector<vector<int>>& map)
{
	if (count == 6)
	{
		// ���� ū ��� �� ����
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > answer)
				{
					answer = map[i][j];
				}
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> newMap = Move(i, map);
		BackTrack(count + 1, newMap);
	}
}

int main()
{
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			board[i][j] = num;
		}
	}

	BackTrack(1, board);

	cout << answer;
	return 0;
}