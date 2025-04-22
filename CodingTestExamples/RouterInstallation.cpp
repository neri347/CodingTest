/// 공유기 설치
/// https://www.acmicpc.net/problem/2110
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, C;
	cin >> N >> C;
	vector<int> routers;
	for (int i = 0; i < N; i++)
	{
		int r;
		cin >> r;
		routers.push_back(r);
	}

	sort(routers.begin(), routers.end());

	int answer = 0;
	int left = 1; // 최소 거리
	int right = routers[N - 1] - routers[0]; // 최대 거리

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int count = 1;
		int lastPos = 0;
		for (int i = 1; i < N; i++)
		{
			if (routers[i] - routers[lastPos] >= mid)
			{
				++count;
				lastPos = i;
			}
		}

		if (count >= C)
		{
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << answer;
	return 0;
}