/// 시험 감독
/// https://www.acmicpc.net/problem/13458
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long long answer = 0;
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		nums[i] = num;
	}
	int B, C;
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		// 한 시험장에 1명의 총감독관
		int p = nums[i] - B; // 부감독관이 감시해야 하는 응시자 수
		++answer;
		if (p <= 0)
		{
			continue;
		}

		int value = ceil(static_cast<float>(p) / C); // 필요한 부감독관 수
		answer += value;
	}
	cout << answer;

	return 0;
}