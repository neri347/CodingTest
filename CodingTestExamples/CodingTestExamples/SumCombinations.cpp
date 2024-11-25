/// p.541 문제47 1부터 N까지 숫자 중 합이 10이 되는 조합 구하기
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> results;
vector<int> vec;

void BackTrack(int start, int end, int sum)
{
	if (sum == 10)
	{
		results.push_back(vec);
		return;
	}

	for (int i = start; i <= end; i++)
	{
		if (i + sum <= 10)
		{
			vec.push_back(i);
			BackTrack(i + 1, end, i + sum);
			vec.pop_back();
		}
	}
}

vector<vector<int>> solution(int N)
{
	BackTrack(1, N, 0);
	return results;
}

int main()
{
	for (auto& v : solution(5))
	{
		for (int e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}