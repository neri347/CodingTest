/// ºÎºÐÇÕ
/// https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;

int main()
{
	int N, S;
	cin >> N >> S;
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}

	int left = 0;
	int right = 1;
	int sum = vec[0];
	int answer = MAX;
	while (left < right)
	{
		if (sum >= S)
		{
			answer = min(answer, right - left);
			sum -= vec[left++];
		}
		else
		{
			if (right < N)
			{
				sum += vec[right++];
			}
			else
			{
				sum -= vec[left++];
			}
		}
	}
	answer == MAX ? cout << 0 : cout << answer;
	return 0;
}