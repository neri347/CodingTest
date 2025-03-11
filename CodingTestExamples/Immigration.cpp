/// 입국심사
/// https://school.programmers.co.kr/learn/courses/30/lessons/43238
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	long long left = 1;
	long long right = 1e18;

	while (left < right)
	{
		long long mid = left + (right - left) / 2;

		long long count = 0;
		for (int i = 0; i < times.size(); i++)
		{
			count += mid / times[i];
		}

		if (count >= n)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int main()
{

	return 0;
}