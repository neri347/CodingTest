/// 연속합
/// https://www.acmicpc.net/problem/1912
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int size;
	cin >> size;
	vector<int> numbers;
	for (int i = 0; i < size; ++i)
	{
		int n;
		cin >> n;
		numbers.push_back(n);
	}

	// 풀이
	vector<int> sums(size, 0);
	sums[0] = numbers[0];
	//int ret = sums[0];

	for (int i = 1; i < size; ++i)
	{
		sums[i] = max(sums[i - 1] + numbers[i], numbers[i]);
		//ret = max(ret, sums[i]);
	}

	cout << *max_element(sums.begin(), sums.end());
	return 0;
}