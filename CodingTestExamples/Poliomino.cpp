/// 폴리오미노
/// https://www.acmicpc.net/problem/1343
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	string board;
	cin >> board;

	string answer;
	int count = 0;
	for (char& ch : board)
	{
		if (ch == 'X')
		{
			count++;
		}
		else
		{
			if (count % 2 != 0)
			{
				cout << -1;
				return 0;
			}
			for (int i = 0; i < count / 4; i++)
			{
				answer += "AAAA";
			}
			count = count % 4;
			for (int i = 0; i < count / 2; i++)
			{
				answer += "BB";
			}
			count = count % 2;
			answer += ch;
		}
	}

	if (count % 2 != 0)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < count / 4; i++)
	{
		answer += "AAAA";
	}
	count = count % 4;
	for (int i = 0; i < count / 2; i++)
	{
		answer += "BB";
	}
	count = count % 2;
	
	cout << answer;
	return 0;
}