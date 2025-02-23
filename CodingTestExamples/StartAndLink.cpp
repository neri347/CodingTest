/// 스타트와 링크
/// https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
using namespace std;

int N;
int stats[20][20];
int answer = INT_MAX;

void Backtrack(int index, vector<int>& startTeam)
{
	if (startTeam.size() == N / 2)
	{
		set<int> team;
		for (int i = 0; i < N; i++)
		{
			team.insert(i);
		}
		for (int i = 0; i < startTeam.size(); i++)
		{
			team.erase(startTeam[i]);
		}
		vector<int> linkTeam(team.begin(), team.end());

		// 스타트팀 능력치 합
		int startSum = 0;
		for (int i = 0; i < startTeam.size(); i++)
		{
			for (int j = 0; j < startTeam.size(); j++)
			{
				if (i == j)	continue;
				startSum += stats[startTeam[i]][startTeam[j]];
			}
		}

		// 링크팀 능력치 합
		int linkSum = 0;
		for (int i = 0; i < linkTeam.size(); i++)
		{
			for (int j = 0; j < linkTeam.size(); j++)
			{
				if (i == j)	continue;
				linkSum += stats[linkTeam[i]][linkTeam[j]];
			}
		}

		answer = min(answer, abs(startSum - linkSum));
		return;
	}

	for (int i = index + 1; i < N; i++)
	{
		startTeam.push_back(i);
		Backtrack(i, startTeam);
		startTeam.pop_back();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int s;
			cin >> s;
			stats[i][j] = s;
		}
	}

	vector<int> startTeam;
	for (int i = 0; i < N / 2 - 1; i++)
	{
		startTeam.push_back(i);
		Backtrack(i, startTeam);
		startTeam.pop_back();
	}

	cout << answer;
	return 0;
}