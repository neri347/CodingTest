/// DSLR
/// https://www.acmicpc.net/problem/9019
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int start, end;
		cin >> start >> end;

		bool isVisited[10000] = { false, };
		string answer;
		queue<pair<int, string>> q; // curNum, commands
		q.push({ start, "" });
		isVisited[start] = true;

		while (!q.empty())
		{
			int curNum = q.front().first;
			string commands = q.front().second;
			q.pop();

			if (curNum == end)
			{
				answer = commands;
				break;
			}

			// D
			int d = (curNum * 2) % 10000;
			if (!isVisited[d])
			{
				isVisited[d] = true;
				q.push({ d, commands + 'D' });
			}
			// S
			int s = curNum - 1;
			if (s < 0)
			{
				s = 9999;
			}
			if (!isVisited[s])
			{
				isVisited[s] = true;
				q.push({ s, commands + 'S' });
			}
			
			// L
			int l = (curNum % 1000) * 10 + (curNum / 1000);
			if (!isVisited[l])
			{
				isVisited[l] = true;
				q.push({ l, commands + 'L' });
			}

			// R
			int r = (curNum / 10) + (curNum % 10) * 1000;
			if (!isVisited[r])
			{
				isVisited[r] = true;
				q.push({ r, commands + 'R' });
			}
		}
		cout << answer << '\n';
	}
	return 0;
}