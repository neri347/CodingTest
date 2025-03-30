/// 안정적인 구간
/// https://www.acmicpc.net/contest/problem/1467/4
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}

	set<int> temp;
	temp.insert(vec[0]);
	for (int i = 1; i < N; i++)
	{
		temp.insert(vec[i]);
		int index = temp.size() / 2;
		auto iter = temp.begin();
		for (int i = 0; i < index; i++)
		{
			++iter;
		}
		if (vec[index] == *iter)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}