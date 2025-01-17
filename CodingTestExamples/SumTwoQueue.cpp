/// 두 큐 합 같게 만들기
/// https://school.programmers.co.kr/learn/courses/30/lessons/118667
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = 0;

	vector<int> vec;
	long long sum1 = 0;
	long long sum2 = 0;
	int n = queue1.size() + queue2.size();
	for (int i = 0; i < queue1.size(); ++i)
	{
		sum1 += queue1[i];
		vec.push_back(queue1[i]);
	}
	for (int i = 0; i < queue2.size(); ++i)
	{
		sum2 += queue2[i];
		vec.push_back(queue2[i]);
	}
	long long goal = (sum1 + sum2) / 2;

	if ((sum1 + sum2) % 2 != 0)
	{
		return -1;
	}

	if (*max_element(queue1.begin(), queue1.end()) > goal ||
		*max_element(queue2.begin(), queue2.end()) > goal)
	{
		return -1;
	}

	int left = 0;
	int right = queue1.size();
	while (right < vec.size() && left <= right)
	{
		if (sum1 < goal)
		{
			sum1 += vec[right++];
		}
		else if (sum1 > goal)
		{
			sum1 -= vec[left++];
		}
		else // 목표값 달성
		{
			break;
		}
		++answer;
	}

	return sum1 == goal ? answer : -1;
}

int main()
{

	return 0;
}