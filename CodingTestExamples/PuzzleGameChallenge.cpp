/// ���� ���� ç����
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
		int mid = (left + right) / 2; // // ���� ���õ�(level)
		long long time = 0;
		for (int i = 0; i < diffs.size(); i++)
		{
			// diff <= level�̸� times[i]��ŭ�� �ð��� ����Ͽ� �ذ�
			if (diffs[i] <= mid)
			{
				time += times[i];
			}
			else // diff > level�̸� ������ diff-level��ŭ Ʋ��
			{
				// ������ Ʋ�� ������ times[i] + times[i-1]��ŭ �ð� ���
				// ������ diff-level��ŭ Ʋ�� ���Ŀ��� times[i]�� �ð� ���
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