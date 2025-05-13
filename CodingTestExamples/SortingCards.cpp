/// 카드 정렬하기
/// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		pq.push(v);
	}

	int answer = 0;
	while (pq.size() != 1)
	{
		int v1 = pq.top();
		pq.pop();
		int v2 = pq.top();
		pq.pop();
		int sum = v1 + v2;
		answer += sum;
		pq.push(sum);
	}
	cout << answer;
	return 0;
}