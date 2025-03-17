/// N°ú M(12)
/// https://www.acmicpc.net/problem/15666
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int N, M;
vector<int> vec;
vector<int> temp;
set<vector<int>> ret;

void DFS(int num, int count)
{
	if (count == M)
	{
		ret.insert(temp);
		return;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < num)
		{
			continue;
		}
		temp.push_back(vec[i]);
		DFS(vec[i], count + 1);
		temp.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}
	
	DFS(0, 0);

	for (auto& vec : ret)
	{
		for (auto& v : vec)
		{
			cout << v << ' ';
		}
		cout << '\n';
	}

	return 0;
}