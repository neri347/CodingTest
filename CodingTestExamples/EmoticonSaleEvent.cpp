/// 이모티콘 할인행사
/// https://school.programmers.co.kr/learn/courses/30/lessons/150368
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int people;
int money;
vector<int> cost;

void DFS(int count, const vector<vector<int>>& users, const vector<int>& emoticons)
{
	if (count == emoticons.size())
	{
		int m = 0;
		int p = 0;
		for (int i = 0; i < cost.size(); i++)
		{
			if (cost[i] >= users[i][1])
			{
				p++;
			}
			else
			{
				m += cost[i];
			}
		}
		// 결과 저장
		if (p > people)
		{
			people = p;
			money = m;
		}
		else if (p == people)
		{
			if (m > money)
			{
				money = m;
			}
		}

		return;
	}

	for (int i = 1; i <= 4; i++) // i * 10 = 할인율
	{
		for (int j = 0; j < users.size(); j++)
		{
			if (users[j][0] <= i * 10)
			{
				cost[j] += emoticons[count] * (100 - i * 10) / 100;
			}
		}
		DFS(count + 1, users, emoticons);
		for (int j = 0; j < users.size(); j++)
		{
			if (users[j][0] <= i * 10)
			{
				cost[j] -= emoticons[count] * (100 - i * 10) / 100;
			}
		}
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	cost.assign(users.size(), 0);
	DFS(0, users, emoticons);
	return { people, money };
}

int main()
{
	vector<vector<int>> users = { { 40, 2900 }, { 23, 10000 }, { 11, 5200 }, { 5, 5900 }, { 40, 3100 }, { 27, 9200 }, { 32, 6900 } };
	vector<int> emoticons = { 1300, 1500, 1600, 4900 };
	for (auto& e : solution(users, emoticons))
	{
		cout << e << " ";
	}
	return 0;
}