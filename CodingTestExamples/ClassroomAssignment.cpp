/// 강의실 배정
/// https://www.acmicpc.net/problem/11000
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> classes;
	for (int i = 0; i < N; i++)
	{
		int s, t;
		cin >> s >> t;
		classes.push_back({ s, t });
	}

	sort(classes.begin(), classes.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		pq.push(classes[i].second);
		if (pq.top() <= classes[i].first) pq.pop();
	}

	cout << pq.size();

	return 0;
}