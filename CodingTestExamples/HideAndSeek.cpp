/// ¼û¹Ù²ÀÁú
/// https://www.acmicpc.net/problem/1697
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
bool isVisited[100001];
int counts[100001];

int main()
{
	cin >> N >> K;	

	queue<int> q;
	q.push(N);
	isVisited[N] = true;

	while (!q.empty())
	{
		int cx = q.front();
		if (cx == K) break;
		q.pop();

		if (cx - 1 >= 0 && cx - 1 <= 100000 && !isVisited[cx - 1])
		{
			isVisited[cx - 1] = true;
			counts[cx - 1] = counts[cx] + 1;
			q.push(cx - 1);
		}
		if (cx + 1 >= 0 && cx + 1 <= 100000 && !isVisited[cx + 1])
		{
			isVisited[cx + 1] = true;
			counts[cx + 1] = counts[cx] + 1;
			q.push(cx + 1);
		}
		if (cx * 2 >= 0 && cx * 2 <= 100000 && !isVisited[cx * 2])
		{
			isVisited[cx * 2] = true;
			counts[cx * 2] = counts[cx] + 1;
			q.push(cx * 2);
		}
	}

	cout << counts[K];

	return 0;
}