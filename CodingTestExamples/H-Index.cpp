/// H-Index
/// https://school.programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int counts[10001] = { 0, };
	int answer = 0;

	for (int i = 0; i < citations.size(); i++)
	{
		counts[citations[i]]++;
	}

	int sum = citations.size();
	// i �ο�Ƚ��
	for (int i = 0; i < 10000; i++)
	{
		// i�� �̻� �ο�� �� ���� = sum
		// i�� �̻� �ο�� �� ������ i�� �̸��̸� �ߴ�
		if (sum < i) break;
		// i�� �̻� �ο���� ���� �� ������ i�� ���϶�� h�� ����
		if ((citations.size() - sum) <= i)
		{
			answer = i;
		}
		// sum �� ����
		sum -= counts[i];
	}

	return answer;
}

int main()
{

	return 0;
}