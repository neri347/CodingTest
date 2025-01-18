/// 랜선 자르기
/// https://www.acmicpc.net/problem/1654
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int K, N;
	cin >> K >> N;
	vector<int> wires;
	for (int i = 0; i < K; ++i)
	{
		int num;
		cin >> num;
		wires.push_back(num);
	}
	
	long long low = 1;
	long long high = *max_element(wires.begin(), wires.end());
	int answer = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		int count = 0;
		for (int i = 0; i < K; ++i)
		{
			count += wires[i] / mid;
		}
		if (count >= N)
		{
			low = mid + 1;
			if (answer < mid)
			{
				answer = mid;
			}
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << answer;

	return 0;
}