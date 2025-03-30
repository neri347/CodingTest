/// �����̾� ��Ʈ ���� �κ�
/// https://www.acmicpc.net/problem/20055
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// �κ��� �ø��� ��ġ���� �ø� �� �ִ�. �������� �κ��� ������ ��ġ�� �����ϸ� �� ��� ������. 
// �κ��� �ø��� ��ġ�� �ø��ų� �κ��� � ĭ���� �̵��ϸ� �� ĭ�� �������� ��� 1��ŭ �����Ѵ�.

int main()
{
	int N, K;
	cin >> N >> K;
	deque<pair<int, bool>> belt;
	for (int i = 0; i < 2 * N; i++)
	{
		int d;
		cin >> d;
		belt.push_back({ d, false });
	}

	int answer = 0;
	while (true)
	{
		++answer;
		// 1. ��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.
		auto back = belt.back();
		belt.pop_back();
		belt.push_front(back);
		// �κ��� ������ ��ġ�� �����ϸ� �� ��� ������.
		if (belt[N - 1].second)
		{
			belt[N - 1].second = false;
		}

		// 2. ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�.
		// ���� �̵��� �� ���ٸ� ������ �ִ´�.
		//		1.�κ��� �̵��ϱ� ���ؼ��� �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� ���� �־�� �Ѵ�.
		for (int i = N - 2; i >= 0; i--)
		{
			if (belt[i].second && belt[i + 1].first >= 1 && belt[i + 1].second == false)
			{
				belt[i + 1].first--;
				belt[i + 1].second = true;
				belt[i].second = false;
			}
		}
		// �κ��� ������ ��ġ�� �����ϸ� �� ��� ������.
		if (belt[N - 1].second)
		{
			belt[N - 1].second = false;
		}

		// 3. �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
		if (belt[0].first >= 1 && belt[0].second == false)
		{
			belt[0].first--;
			belt[0].second = true;
		}

		// 4. �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�.�׷��� �ʴٸ� 1������ ���ư���.
		int count = 0;
		for (int i = 0; i < 2 * N; i++)
		{
			if (belt[i].first == 0)
			{
				++count;
			}
		}
		if (count >= K)
		{
			break;
		}
	}
	cout << answer;
	return 0;
}