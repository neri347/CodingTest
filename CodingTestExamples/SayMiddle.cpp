/// 가운데를 말해요
/// https://www.acmicpc.net/problem/1655
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int>> minpq;
	priority_queue<int, vector<int>, less<int>> maxpq;

	int value;
	scanf("%d", &value);
	minpq.push(value);
	printf("%d\n", minpq.top());

	for (int i = 1; i < N; i++)
	{
		scanf("%d", &value);
		minpq.push(value);
		if (i % 2 == 1)
		{
			// 짝수번째 차례
			int smallestInMinpq = minpq.top();
			minpq.pop();
			maxpq.push(smallestInMinpq);
		}

		if (minpq.top() < maxpq.top())
		{
			int smallestInMinpq = minpq.top();
			int biggestInMaxpq = maxpq.top();
			minpq.pop();
			maxpq.pop();
			minpq.push(biggestInMaxpq);
			maxpq.push(smallestInMinpq);
		}

		if (minpq.size() == maxpq.size())
		{
			printf("%d\n", maxpq.top());
		}
		else
		{
			printf("%d\n", minpq.top());
		}
	}

	return 0;
}