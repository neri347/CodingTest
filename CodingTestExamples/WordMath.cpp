/// 단어 수학
/// https://www.acmicpc.net/problem/1339
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> strs;
	unordered_map<char, int> m;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		strs.push_back(str);
		int mul = 1;
		for (int j = str.size() - 1; j >= 0; j--)
		{
			m[str[j]] += mul;
			mul *= 10;
		}
	}

	vector<int> vec;
	for (auto& [ch, n] : m)
	{
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end(), greater<int>());

	int answer = 0;
	int num = 9;
	for (int i = 0; i < vec.size(); i++)
	{
		answer += vec[i] * num;
		num--;
	}
	cout << answer;
	return 0;
}