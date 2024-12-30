/// ī��
/// https://school.programmers.co.kr/learn/courses/30/lessons/42842
/// �簢���� �Ǵ� ���� üũ
/// ������ ���� �ּҰ�~�ִ밪 ������ ����3�� ���� �Ͻ����־���.
/// �簢���� ���̿� ������ ���� ������ �־��� ���̴�.
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int total = brown + yellow;
	int maxVertical = sqrt(total);
	// ���α��̴� �ּ� 3, �ִ� sqrt(total)
	for (int i = 3; i <= maxVertical; ++i)
	{
		// ������ ���α��̷� �簢���� ���� �� �ִ��� Ȯ��
		if (total % i == 0)
		{
			int horizon = total / i;
			if (2 * i + 2 * (horizon - 2) == brown)
			{
				return { horizon, i };
			}
		}
	}

	return answer;
}

int main()
{

	return 0;
}