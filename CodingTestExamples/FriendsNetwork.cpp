/// 模备 匙飘况农
/// https://www.acmicpc.net/problem/4195
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string Find(string name, unordered_map<string, string>& parents)
{
	if (parents[name] == name)
	{
		return name;
	}
	parents[name] = Find(parents[name], parents);
	return parents[name];
}

void Union(string name1, string name2, unordered_map<string, string>& parents, unordered_map<string, int>& counts)
{
	string root1 = Find(name1, parents);
	string root2 = Find(name2, parents);
	if (root1 != root2)
	{
		parents[root2] = root1;
		counts[root1] += counts[root2];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int F;
		cin >> F;
		unordered_map<string, string> parents;
		unordered_map<string, int> counts;
		for (int f = 0; f < F; f++)
		{
			string name1, name2;
			cin >> name1 >> name2;
			if (parents.count(name1) == 0)
			{
				parents[name1] = name1;
				counts[name1] = 1;
			}
			if (parents.count(name2) == 0)
			{
				parents[name2] = name2;
				counts[name2] = 1;
			}
			Union(name1, name2, parents, counts);
			cout << counts[parents[name1]] << '\n';
		}
	}
	return 0;
}