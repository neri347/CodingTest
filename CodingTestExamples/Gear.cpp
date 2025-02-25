/// ��Ϲ���
/// https://www.acmicpc.net/problem/14891
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	vector<vector<int>> gears(4);
	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;
		for (char ch : str)
		{
			gears[i].push_back(ch - '0');
		}
	}

	int N;
	cin >> N;
	vector<pair<int, int>> rotate; // index, dir
	for (int i = 0; i < N; i++)
	{
		int index, dir; // dir 1 �ð����, -1 �ݽð����
		cin >> index >> dir;
		rotate.push_back({ index - 1, dir });
	}

	// Ǯ��
	for (int i = 0; i < N; i++)
	{
		queue<pair<int, int>> q; // index, dir
		vector<bool> isVisited(4, false);
		q.push({ rotate[i].first, rotate[i].second });
		isVisited[rotate[i].first] = true;

		while (!q.empty())
		{
			int index = q.front().first;
			int dir = q.front().second;
			int right = gears[index][2];
			int left = gears[index][6];
			q.pop();

			// ��� ȸ��
			if (dir == 1) // �ð���� ȸ��
			{
				int v = gears[index][7];
				// ���� �ڷ� �б�
				for (int i = 6; i >= 0; i-- )
				{
					gears[index][i + 1] = gears[index][i];
				}
				gears[index][0] = v;
			}
			else
			{
				int v = gears[index][0];
				// ���� ������ �����
				for (int i = 0; i < 7; i++)
				{
					gears[index][i] = gears[index][i + 1];
				}
				gears[index][7] = v;
			}

			// ���� ��� üũ
			if (index - 1 >= 0)
			{
				if (!isVisited[index - 1])
				{
					// ���� ��Ͽ� ���� ��ϰ� ���� ������ ȸ������ ����
					if (left != gears[index - 1][2])
					{
						isVisited[index - 1] = true;
						if (dir == 1)
						{
							q.push({ index - 1, -1 });
						}
						else
						{
							q.push({ index - 1, 1 });
						}
					}
				}
			}

			// ������ ��� üũ
			if (index + 1 <= 3)
			{
				if (!isVisited[index + 1])
				{
					// ���� ��Ͽ� ���� ��ϰ� ���� ������ ȸ������ ����
					if (right != gears[index + 1][6])
					{
						isVisited[index + 1] = true;
						if (dir == 1)
						{
							q.push({ index + 1, -1 });
						}
						else
						{
							q.push({ index + 1, 1 });
						}
					}
				}
			}
		}
	}

	//1�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 1��
	//2�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 2��
	// 3�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 4��
	// 4�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 8��
	int answer = 0;
	int value = 1;
	for (int i = 0; i < 4; i++)
	{
		if (gears[i][0] == 1)
		{
			answer += value;
		}
		value *= 2;
	}
	cout << answer;

	return 0;
}