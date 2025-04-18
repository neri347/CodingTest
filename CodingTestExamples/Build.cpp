/// µ¢Ä¡
/// https://www.acmicpc.net/problem/7568
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> builds;
	for (int i = 0; i < N; i++)
	{
		int w, h;
		cin >> w >> h;
		builds.push_back({ w, h });
	}

	vector<int> ranks(N);
	for (int i = 0; i < builds.size(); i++)
	{
		int rank = 1;
		int curWeight = builds[i].first;
		int curHeight = builds[i].second;
		for (int j = 0; j < builds.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			int w = builds[j].first;
			int h = builds[j].second;
			if (w > curWeight && h > curHeight)
			{
				++rank;
			}
		}
		ranks[i] = rank;
	}

	for (int i = 0; i < N; i++)
	{
		cout << ranks[i] << ' ';
	}

	return 0;
}