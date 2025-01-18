/// ���� �� ���ϱ� 4
/// https://www.acmicpc.net/problem/11659
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> answer;
	// �Է�
	int N, M;
	cin >> N >> M;
	vector<int> sums(N + 1, 0);
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		sum += num;
		sums[i + 1] = sum;
	}
	vector<pair<int, int>> pairs;
	for (int i = 0; i < M; ++i)
	{
		int start, end;
		cin >> start >> end;
		pairs.push_back({ start, end });
	}

	// Ǯ��
	for (auto& [start, end] : pairs)
	{
		int s = sums[end] - sums[start - 1];
		answer.push_back(s);
	}

	// ���
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}