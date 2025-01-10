/// ������
/// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<int>> lab2;

void DFS(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (lab2[nx][ny] == 0)
			{
				lab2[nx][ny] = 2;
				DFS(nx, ny);
			}
		}
	}
}

int main()
{
	// �Է�
	cin >> n >> m;
	vector<vector<int>> lab1;
	vector<pair<int, int>> virus;
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < m; ++j)
		{
			int map;
			cin >> map;
			if (map == 2)
			{
				virus.push_back({ i , j });
			}
			temp.push_back(map);
		}
		lab1.push_back(temp);
	}

	// Ǯ��
	for (int i = 0; i < n * m; ++i)
	{
		if (lab1[i / m][i % m] == 0)
		{
			for (int j = i + 1; j < n * m; ++j)
			{
				if (lab1[j / m][j % m] == 0)
				{
					for (int k = j + 1; k < n * m; ++k)
					{
						if (lab1[k / m][k % m] == 0)
						{
							lab2 = lab1;
							// �� �����
							lab2[k / m][k % m] = 1;
							lab2[j / m][j % m] = 1;
							lab2[i / m][i % m] = 1;
							// ���̷��� �ùķ��̼�
							for (int v = 0; v < virus.size(); ++v)
							{
								DFS(virus[v].first, virus[v].second);
							}
							// ���� ���� ����
							int count = 0;
							for (int r = 0; r < n; ++r)
							{
								for (int c = 0; c < m; ++c)
								{
									if (lab2[r][c] == 0)
									{
										++count;
									}
								}
							}
							answer = max(answer, count);
						}
					}
				}				
			}
		}		
	}

	cout << answer;
	return 0;
}