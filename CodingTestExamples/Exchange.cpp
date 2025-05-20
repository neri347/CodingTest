/// 교환
/// https://www.acmicpc.net/problem/1039
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

void swap(int x, int y, string& str)
{
	char ch = str[x];
	str[x] = str[y];
	str[y] = ch;
}

int InvertToInt(string str)
{
	int ret = 0;
	int m = 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		ret += (str[i] - '0') * m;
		m *= 10;
	}
	return ret;
}

int main()
{
	int N, K;
	cin >> N >> K;

	int answer = -1;
	string str = to_string(N);
	queue<string> q;
	q.push(str);

	for (int k = 0; k < K; k++)
	{
		int qs = q.size();
		set<string> visited;
		for (int c = 0; c < qs; c++)
		{
			string s = q.front();
			q.pop();

			for (int i = 0; i < s.size() - 1; i++)
			{
				for (int j = i + 1; j < s.size(); j++)
				{
					if (i == 0 && s[j] == '0') // 바꾼 수가 0으로 시작하면 안 된다.
					{
						continue;
					}
					swap(i, j, s);

					if (visited.count(s) == 0)
					{
						int toInt = InvertToInt(s);
						if (k == K - 1 && answer < toInt)
						{
							answer = toInt;
						}
						q.push(s);
						visited.insert(s);
					}

					// 원상복구
					swap(i, j, s);
				}
			}

		}
	}	
	cout << answer;
	return 0;
}