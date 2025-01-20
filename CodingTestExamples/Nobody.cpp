/// µË∫∏¿‚
/// https://www.acmicpc.net/problem/1764
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
	unordered_set<string> names;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		names.insert(name);
	}

	int count = 0;
	vector<string> answer;
	for (int i = 0; i < M; ++i)
	{
		string name;
		cin >> name;
		if (names.count(name))
		{
			answer.push_back(name);
			++count;
		}
	}

	sort(answer.begin(), answer.end());
	cout << count << "\n";
	for (const auto& str : answer)
	{
		cout << str << "\n";
	}

	return 0;
}