/// 나무 자르기
/// https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> trees;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		trees.push_back(v);
	}

	long long answer = 0;
	long long left = 0;
	long long right = 2'000'000'000;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (auto& len : trees)
		{
			if (mid < len)
			{
				sum += len - mid;
			}
		}
		if (sum >= M)
		{
			answer = mid;
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