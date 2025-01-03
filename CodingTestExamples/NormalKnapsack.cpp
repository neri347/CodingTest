/// ����� �賶
/// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// �Է�
	int N, K;
	cin >> N >> K;
	vector<vector<int>> items;
	for (int i = 0; i < N; ++i)
	{
		int W, V;
		cin >> W >> V;
		items.push_back({ W, V });
	}

	// Ǯ��
	// dp[i][j] = dp[i-1][j] (W > K)
	//			or max(dp[i-1][j], items[i][1] + dp[i-1][K-W])
	vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
	
	for (int i = 1; i <= N; ++i) // �� �Ѱ��Ѱ�
	{
		for (int j = 1; j <= K; ++j) // �����Ѱ踦 1�� �÷����鼭 �˻�
		{
			int weight = items[i-1][0];
			if (weight <= j)
			{
				dp[i][j] = max(dp[i - 1][j], items[i-1][1] + dp[i - 1][j - weight]);
			}
			else // ���� ���� �����Ѱ躸�� ���̴ٸ� �� �ִ´�
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];
	return 0;
}