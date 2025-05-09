/// º¸¼® µµµÏ
/// https://www.acmicpc.net/problem/1202
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> jewels; // weight, value
	for (int i = 0; i < N; i++)
	{
		int m, v;
		cin >> m >> v;
		jewels.push_back({ m, v });
	}
	sort(jewels.begin(), jewels.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first < b.first;
		});

	vector<int> bags;
	for (int i = 0; i < K; i++)
	{
		int c;
		cin >> c;
		bags.push_back(c);
	}
	sort(bags.begin(), bags.end());

	priority_queue<int> pq; // price

	long long answer = 0;
	int index = 0;
	for (int i = 0; i < K; i++)
	{
		while (index < N && jewels[index].first <= bags[i])
		{
			pq.push(jewels[index].second);
			index++;
		}

		if (!pq.empty())
		{
			int p = pq.top();
			answer += p;
			pq.pop();
		}
	}

	cout << answer;

	return 0;
}