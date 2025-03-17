/// 마인크래프트
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

	vector<pair<int, int>> results; // <걸리는 시간, 땅의 높이>
	for (int h = 0; h <= 256; h++) // 목표하는 땅의 높이
	{
		int time = 0; // 걸리는 시간
		int block = B; // 남은 블록
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int height = h - ground[i][j]; // 채워야 하는 높이
				if (height > 0)
				{
					// 인벤토리에서 블록 하나를 꺼내어 좌표(i, j)의 가장 위에 있는 블록 위에 놓는다
					// 1초 소요
					block -= height;
					time += height;
				}
				else if (height < 0)
				{
					// 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다
					// 2초 소요
					block -= height;
					time -= height * 2;
				}
			}
		}

		if (block >= 0) // 남은 블록이 음수라는 것은 가진 블록으로 그 높이를 만들 수 없다는 것
		{
			results.push_back({ time, h });
		}
	}

	sort(results.begin(), results.end(), Cmp);
	cout << results[0].first << ' ' << results[0].second;

	return 0;
}