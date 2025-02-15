/// 퍼즐 게임 챌린지
/// https://school.programmers.co.kr/learn/courses/30/lessons/340212
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
	int answer = 0;
	int left = *min_element(diffs.begin(), diffs.end());
	int right = *max_element(diffs.begin(), diffs.end());

	while (left <= right)
	{
		int mid = (left + right) / 2; // // 현재 숙련도(level)
		long long time = 0;
		for (int i = 0; i < diffs.size(); i++)
		{
			// diff <= level이면 times[i]만큼의 시간을 사용하여 해결
			if (diffs[i] <= mid)
			{
				time += times[i];
			}
			else // diff > level이면 퍼즐을 diff-level만큼 틀림
			{
				// 퍼즐을 틀릴 때마다 times[i] + times[i-1]만큼 시간 사용
				// 퍼즐을 diff-level만큼 틀린 이후에는 times[i]의 시간 사용
				time += (times[i] + times[i - 1]) * (diffs[i] - mid) + times[i];
			}
		}
		if (time == limit)
		{
			return mid;
		}
		else if (time < limit)
		{
			cout << "lv: " << mid << " " << "time: " << time << endl;
			answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return answer;
}

int main()
{

	return 0;
}