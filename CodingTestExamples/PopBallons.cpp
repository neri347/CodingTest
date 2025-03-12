/// ǳ�� �Ͷ߸���
/// https://school.programmers.co.kr/learn/courses/30/lessons/68646
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solution(vector<int> a) {
	if (a.size() <= 2)
	{
		return a.size();
	}

	int answer = 2; // �� ��, �� �� ǳ���� ������ �츱 �� ����
	// i��° ǳ���� �츮����
	// 0 ~ i-1 ��° ǳ������ �Ͷ߷��� ���� ǳ����
	// i+1 ~ �� �� ǳ������ �Ͷ߷��� ���� ǳ����� ��
	// �� ǳ�� �� i��° ǳ������ ū ǳ���� �Ѱ��� ������
	// i��° ǳ�� �츱 �� ����

	// 0��° ~ i��° ��ұ��� �ּҰ� ����
	vector<int> lefts(a.size(), 0);
	int left = INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		left = min(left, a[i]);
		lefts[i] = left;
	}

	// i��° ~ �� ������ ��ұ��� �ּҰ� ����
	int right = INT_MAX;
	vector<int> rights(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		right = min(right, a[a.size() - 1 - i]);
		rights[a.size() - 1 - i] = right;
	}

	// 0~i-1������ �ּҰ�, i+1~�� ������ �ּҰ��� i�� ��
	// �� �� �ϳ� �̻� i�� ���� ũ�� ī��Ʈ �� �� �ø���.
	for (int i = 1; i < a.size() - 1; i++)
	{
		if (lefts[i - 1] > a[i] || rights[i + 1] > a[i])
		{
			++answer;
		}
	}

	return answer;
}

int main()
{

	return 0;
}