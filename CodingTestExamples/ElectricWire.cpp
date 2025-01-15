/// 전깃줄
/// https://www.acmicpc.net/problem/2565
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(int start, int end, int element, const vector<int>& vec)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (vec[mid] < element)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}

	return end;
}

bool Cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}

int main()
{
	// 입력
	int N;
	cin >> N;
	vector<pair<int, int>> wires;
	for (int i = 0; i < N; ++i)
	{
		int n, idx;
		cin >> n >> idx;
		wires.push_back({ n, idx });
	}
	sort(wires.begin(), wires.end(), Cmp);

	// 풀이
	vector<int> vec;
	vec.push_back(wires[0].second);
	for (int i = 1; i < wires.size(); ++i)
	{
		if (wires[i].second > vec.back())
		{
			vec.push_back(wires[i].second);
		}
		else
		{
			int pos = BinarySearch(0, vec.size() - 1, wires[i].second, vec);
			vec[pos] = wires[i].second;
		}
	}
	cout << wires.size() - vec.size();

	return 0;
}