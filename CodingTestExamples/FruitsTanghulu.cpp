/// 과일 탕후루
/// https://www.acmicpc.net/problem/30804
#include <iostream>
#include <vector>
using namespace std;

int fruits[10] = { 0, };

bool Check()
{
	int count = 0;
	for (int i = 1; i < 10; i++)
	{
		if (fruits[i] > 0)
		{
			count++;
		}
	}

	if (count > 2)
	{
		return true;
	}
	return false;
}

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

	int answer = 0;
	int left = 0;
	int right = 0;
	while (left < N)
	{
		while (right < N)
		{
			fruits[vec[right]]++;
			if (Check())
			{
				fruits[vec[right]]--;
				break;
			}
			right++;
		}
		answer = max(answer, right - left);
		fruits[vec[left]]--;
		left++;
	}
	cout << answer;
	return 0;
}