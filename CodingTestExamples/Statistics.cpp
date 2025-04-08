/// ≈Î∞Ë«–
/// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int sum = 0;
	vector<int> vec;
	unordered_map<int, int> um;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		sum += num;
		vec.push_back(num);
		um[num]++;
	}
	sort(vec.begin(), vec.end());

	int avg = round((double)sum / N);
	int midIdx = N / 2;
	int medium = vec[midIdx];
	
	int maxCount = 0;
	for (auto& [num, count] : um)
	{
		if (maxCount < count)
		{
			maxCount = count;
		}
	}
	vector<int> temp;
	for (auto& [num, count] : um)
	{
		if (maxCount == count)
		{
			temp.push_back(num);
		}
	}

	int maxCountNum = 0;
	if (temp.size() > 1)
	{
		sort(temp.begin(), temp.end());
		maxCountNum = temp[1];
	}
	else
	{
		maxCountNum = temp[0];
	}

	int range = vec[N - 1] - vec[0];

	cout << avg << '\n';
	cout << medium << '\n';
	cout << maxCountNum << '\n';
	cout << range;

	return 0;
}