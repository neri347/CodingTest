/// ��� ������
/// https://www.acmicpc.net/problem/2579
/// �������� DP ������ Ǯ���,
/// DP ������ ��ȭ�� ���� ���·� �̷���� �ִ� ��찡 ���� �� ����.
/// ������ �� �ľ��� �� �� ����
/// ù��° ���̽����� �� ���� ���̽��� �ùķ��̼� �ؼ� 
/// ����� �����س��� ��Ģ�� ã�Ƴ� ���� �ִ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// �Է�
	int size;
	cin >> size;
	vector<int> stairScores;
	for (int i = 0; i < size; ++i)
	{
		int score;
		cin >> score;
		stairScores.push_back(score);
	}

	// Ǯ��
	vector<int> dp(size);
	dp[0] = stairScores[0];
	dp[1] = stairScores[0] + stairScores[1];
	dp[2] = max(stairScores[0] + stairScores[2], stairScores[1] + stairScores[2]);

	for (int i = 3; i < size; ++i)
	{
		dp[i] = max(stairScores[i] + stairScores[i - 1] + dp[i - 3], stairScores[i] + dp[i - 2]);
	}

	cout << dp[size - 1];

	return 0;
}