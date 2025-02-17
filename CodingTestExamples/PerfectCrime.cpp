/// ��������
/// https://school.programmers.co.kr/learn/courses/30/lessons/389480
/// ó������ DFS�� �̿��� ���� Ž�� �˰������� Ǯ������, �ð��ʰ��� ����.
/// ������ ������ 40���̹Ƿ�, ���� Ž�� �˰����� �̿��ϸ� 2^40���� ����� Ȯ���ؾ� �ϹǷ� �ð��ʰ��� �� �� �ۿ� ���� ���̴�.
/// �׷��� DP�� ���� Ǯ����.
/// dp���� ������ (������ ����) * (b�� ���� �� �ִ� �ִ� ���� ����) ��ŭ ���־���.
/// b�� n��(n >= 0 && n < m)�� ������ ������ �� a�� ���� ������ ������ �����Ѵ�.
/// �׷��� dp[info.size()][i] (i >= 0 && i < m) �� �ּҰ��� ã���� �װ��� ���� �ȴ�.
/// dp ���� ������ ���� a�� ������ ������ ���� b�� ������ ������ ��� 2������ dp���Ϳ� ����� ���ش�.
/// a�� ������ ����� ��� ������ ���� ���������� �̹��� ���� ������ ������ �����ָ� �ȴ�.
/// b�� ������ ����� ���, b�� ���� ������ m���� �۾ƾ� �ϰ�, Ȯ���ؼ� ������ ���� �� �ִٸ�
/// ������ a�� ������ ���� ������ �״�� �����ϸ� �ȴ�. (dp�� ����ϴ� ���� a�� ����� ���� �����̱� ����)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
	const int INF = 1000000;
	vector<vector<int>> dp(info.size() + 1, vector<int>(m, INF)); // a�� ���� ���� ����
	for (int i = 0; i < m; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= info.size(); i++)
	{
		int a = info[i - 1][0];
		int b = info[i - 1][1];
		for (int j = 0; j < m; j++)
		{
			// a ����
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
			// b ����
			if (j + b < m)
			{
				dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
			}
		}
	}

	int answer = INF;
	for (int i = 0; i < m; i++)
	{
		answer = min(answer, dp[info.size()][i]);
	}
	return answer < n ? answer : -1;
}

int main()
{
	/*vector<vector<int>> info = { {1,2},{2,3},{2,1} };
	int n = 4;
	int m = 4;*/
	vector<vector<int>> info = { {5,1},{4,1},{3,1}, {2,1}, {1,1} };
	int n = 1;
	int m = 4;
	cout << solution(info, n, m);
	return 0;
}