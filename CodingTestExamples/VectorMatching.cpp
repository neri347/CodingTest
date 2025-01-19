/// º¤ÅÍ ¸ÅÄª
/// https://www.acmicpc.net/problem/1007
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N;
double ret;
bool isVisited[20];
vector<pair<int, int>> vertex;

double Sum()
{
	pair<int, int> distance = { 0, 0 };
	for (int i = 0; i < N; ++i)
	{
		if (isVisited[i]) // ½ÃÀÛÁ¡
		{
			distance.first -= vertex[i].first;
			distance.second -= vertex[i].second;
		}
		else // ³¡Á¡
		{
			distance.first += vertex[i].first;
			distance.second += vertex[i].second;
		}
	}
	return sqrt(pow(distance.first, 2) + pow(distance.second, 2));
}

void DFS(int n, int cnt)
{
	if (cnt == N / 2)
	{
		// º¤ÅÍ ¸ÅÄª ÇÕ ±¸ÇÏ±â
		ret = min(ret, Sum());
		return;
	}

	for (int i = n; i < N; ++i)
	{
		isVisited[i] = true;
		DFS(i + 1, cnt + 1);
		isVisited[i] = false;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(isVisited, 0, sizeof(isVisited));
		vertex.clear();
		ret = 1e9 + 7;

		int x, y;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> x >> y;
			vertex.push_back({ x, y });
		}

		DFS(0, 0);
		printf("%.7lf\n", ret);
	}

	return 0;
}