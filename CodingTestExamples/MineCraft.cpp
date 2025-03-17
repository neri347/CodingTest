/// ����ũ����Ʈ
/// https://www.acmicpc.net/problem/18111
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ground[500][500];

bool Cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main()
{
	int N, M, B;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int v;
			cin >> v;
			ground[i][j] = v;
		}
	}

	vector<pair<int, int>> results; // <�ɸ��� �ð�, ���� ����>
	for (int h = 0; h <= 256; h++) // ��ǥ�ϴ� ���� ����
	{
		int time = 0; // �ɸ��� �ð�
		int block = B; // ���� ���
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int height = h - ground[i][j]; // ä���� �ϴ� ����
				if (height > 0)
				{
					// �κ��丮���� ��� �ϳ��� ������ ��ǥ(i, j)�� ���� ���� �ִ� ��� ���� ���´�
					// 1�� �ҿ�
					block -= height;
					time += height;
				}
				else if (height < 0)
				{
					// ��ǥ (i, j)�� ���� ���� �ִ� ����� �����Ͽ� �κ��丮�� �ִ´�
					// 2�� �ҿ�
					block -= height;
					time -= height * 2;
				}
			}
		}

		if (block >= 0) // ���� ����� ������� ���� ���� ������� �� ���̸� ���� �� ���ٴ� ��
		{
			results.push_back({ time, h });
		}
	}

	sort(results.begin(), results.end(), Cmp);
	cout << results[0].first << ' ' << results[0].second;

	return 0;
}