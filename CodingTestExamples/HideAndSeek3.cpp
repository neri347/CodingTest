/// ¼û¹Ù²ÀÁú 3
/// https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
bool isVisited[MAX];

int main()
{
	int N, K;
	cin >> N >> K;
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	isVisited[N] = true;

	int answer = -1;
	while (!q.empty())
	{
		int pos = q.front().first;
		int count = q.front().second;
		q.pop();

		if (pos == K)
		{
			answer = count;
			break;
		}

		int npos = pos * 2;
		if (npos >= 0 && npos < MAX && !isVisited[npos])
		{
			isVisited[npos] = true;
			q.push({ npos, count });
		}
		npos = pos - 1;
		if (npos >= 0 && npos < MAX && !isVisited[npos])
		{
			isVisited[npos] = true;
			q.push({ npos, count + 1 });
		}
		npos = pos + 1;
		if (npos >= 0 && npos < MAX && !isVisited[npos])
		{
			isVisited[npos] = true;
			q.push({ npos, count + 1 });
		}		
	}
	cout << answer;
	return 0;
}