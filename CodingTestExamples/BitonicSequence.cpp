/// 가장 긴 바이토닉 부분 수열
/// https://www.acmicpc.net/problem/11054
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	vector<int> dp1(n, 0);
	vector<int> dp2(n, 0);
	for (int i = 0; i < n; ++i)
	{
		dp1[i] = 1;
		dp2[n - 1 - i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (numbers[j] < numbers[i])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
			if (numbers[n - 1 - j] < numbers[n - 1 - i])
			{
				dp2[n - 1 - i] = max(dp2[n - 1 - i], dp2[n - 1 - j] + 1);
			}
		}
	}

	int value = dp1[0] + dp2[0];
	for (int i = 1; i < n; ++i)
	{
		value = max(value, dp1[i] + dp2[i]);
	}
	cout << value - 1;

	return 0;
}