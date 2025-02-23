/// ���� ����
/// https://www.acmicpc.net/problem/13458
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long long answer = 0;
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		nums[i] = num;
	}
	int B, C;
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		// �� �����忡 1���� �Ѱ�����
		int p = nums[i] - B; // �ΰ������� �����ؾ� �ϴ� ������ ��
		++answer;
		if (p <= 0)
		{
			continue;
		}

		int value = ceil(static_cast<float>(p) / C); // �ʿ��� �ΰ����� ��
		answer += value;
	}
	cout << answer;

	return 0;
}