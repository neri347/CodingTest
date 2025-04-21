/// 순회강연
/// https://www.acmicpc.net/problem/2109
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first < b.first;
	}
};

int main()
{
	int N;
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	for (int i = 0; i < N; i++)
	{
		int p, d;
		cin >> p >> d;
		pq.push({ p, d });
	}

	int answer = 0;
	vector<int> schedules(10001, 0);
	while (!pq.empty())
	{
		int pay = pq.top().first;
		int day = pq.top().second;
		pq.pop();

		for (int d = day; d >= 1; d--)
		{
			// d번째 날에 강연이 없다면 현재 강연을 스케줄에 잡는다.
			if (schedules[d] == 0)
			{
				schedules[d] = pay;
				answer += pay;
				break;
			}
		}
	}
	cout << answer;
	return 0;
}