/// 구간 합 구하기 5
/// https://www.acmicpc.net/problem/11660
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> sums(N + 1, vector<int>(N + 1, 0)); // 그 줄의 합계
	for (int i = 1; i <= N; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= N; ++j)
		{
			int num;
			cin >> num;
			sum += num;
			sums[i][j] = sum;
		}
	}

	vector<int> answer;
	for (int i = 0; i < M; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int s = 0;
		for (int h = x1; h <= x2; ++h)
		{
			s += sums[h][y2] - sums[h][y1-1];
		}
		answer.push_back(s);
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}