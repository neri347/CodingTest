/// N°ú M(9)
/// https://www.acmicpc.net/problem/15663
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
vector<int> nums;
set<vector<int>> combi;

void DFS(int count, vector<int>& temp, vector<bool>& isVisited)
{
	if (count == M)
	{
		combi.insert(temp);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!isVisited[i])
		{
			isVisited[i] = true;
			temp.push_back(nums[i]);
			DFS(count + 1, temp, isVisited);
			temp.pop_back();
			isVisited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	nums.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	
	for (int start = 0; start < N; start++)
	{
		vector<int> temp;
		temp.push_back(nums[start]);
		vector<bool> isVisited(N, false);
		isVisited[start] = true;
		DFS(1, temp, isVisited);
	}
	for (auto& v : combi)
	{
		for (auto& e : v)
		{
			cout << e << ' ';
		}
		cout << '\n';
	}

	return 0;
}