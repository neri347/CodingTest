/// È¸Àü ÃÊ¹ä
/// https://www.acmicpc.net/problem/2531
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}

	int answer = 0;
	unordered_map<int, int> choice;
	int end = 0;
	for (int i = 0; i < k; i++)
	{
		choice[vec[i]]++;
		++end;
	}
	choice[c]++;
	answer = choice.size();
	choice[vec[0]]--;
	if (choice[vec[0]] <= 0)
	{
		choice.erase(vec[0]);
	}

	for (int start = 1; start < N; start++)
	{
		choice[vec[end]]++;
		end++;
		if (end >= N)
		{
			end = 0;
		}

		answer = max(answer, (int)choice.size());
		choice[vec[start]]--;
		if (choice[vec[start]] <= 0)
		{
			choice.erase(vec[start]);
		}
	}
	cout << answer;
	return 0;
}