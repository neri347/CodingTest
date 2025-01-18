/// 수열
/// https://www.acmicpc.net/problem/2559
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ret[5] = sums[5] - sums[0]
// ret[6] = sums[6] - sums[1]
// ret[7] = sums[7] - sums[2]
int main()
{
	// 입력
	int N, K;
	cin >> N >> K;
	vector<int> sums(N + 1, 0);
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		sum += num;
		sums[i + 1] = sum;
	}

	vector<int> temperatures;
	for (int i = K; i <= N; ++i)
	{
		temperatures.push_back(sums[i] - sums[i - K]);
	}
	cout << *max_element(temperatures.begin(), temperatures.end());
	return 0;
}