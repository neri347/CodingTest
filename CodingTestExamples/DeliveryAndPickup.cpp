/// 택배 배달과 수거하기
/// https://school.programmers.co.kr/learn/courses/30/lessons/150369
#include <iostream>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = 0;
	int deliverySum = 0;
	int pickupSum = 0;
	int count = 0;
	// 제일 먼 집부터 배달
	for (int i = n - 1; i >= 0; i--)
	{
		count = 0;
		deliverySum += deliveries[i];
		pickupSum += pickups[i];

		while (deliverySum > 0 || pickupSum > 0)
		{
			deliverySum -= cap;
			pickupSum -= cap;
			++count;
		}

		answer += (i + 1) * 2 * count;
	}
	return answer;
}

int main()
{

	return 0;
}