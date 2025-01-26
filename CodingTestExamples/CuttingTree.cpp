/// 나무 자르기
/// https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> trees;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		trees.push_back(num);
	}

	int maxTree = *max_element(trees.begin(), trees.end());
	long long answer = 0;
	// 이분탐색
	long long left = 0;
	long long right = maxTree - 1;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (trees[i] > mid)
			{
				int cut = trees[i] - mid;
				sum += cut;
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