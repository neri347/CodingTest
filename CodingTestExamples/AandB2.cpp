/// A¿Í B 2
/// https://www.acmicpc.net/problem/12919
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	string S;
	string T;
	cin >> S >> T;
	queue<string> q;
	q.push(T);

	int answer = 0;
	while (!q.empty())
	{
		string str = q.front();
		q.pop();

		if (str.empty())
		{
			break;
		}

		if (str == S)
		{
			answer = 1;
			break;
		}

		if (str[str.size() - 1] == 'A')
		{
			str.pop_back();
			q.push(str);
			str += 'A';
		}

		reverse(str.begin(), str.end());
		if (str[str.size() - 1] == 'B')
		{
			str.pop_back();
			q.push(str);
		}
	}
	cout << answer;
	return 0;
}