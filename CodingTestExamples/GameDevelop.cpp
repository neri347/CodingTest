/// ���� ����
/// https://www.acmicpc.net/problem/1516
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> connected(n);
	vector<int> degree(n, 0);
	vector<int> time(n, 0);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		time[i] = t;
		while (true)
		{
			int num;
			cin >> num;
			if (num == -1)
			{
				break;
			}
			connected[num - 1].push_back(i);
			degree[i]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (degree[i] == 0)
		{
			q.push(i);
			dp[i] = time[i];
		}
	}

	// ��������
	for (int i = 0; i < n; ++i)
	{
		int idx = q.front();
		q.pop();
		
		// �� ���� ����� ������� ������ ���´� -> ����� ������ ������ 1�� ��������
		// A �ǹ��� ���� ���� �ɸ��� �ð���
		// A �ǹ��� ���� ���� ���� ����� �ϴ� �ǹ��� �߿��� ���� ���� �ɸ��� �ð� + A �ǹ� ���µ� �ɸ��� �ð�
		for (int j = 0; j < connected[idx].size(); ++j)
		{
			int connectedNode = connected[idx][j];
			dp[connectedNode] = max(dp[connectedNode], dp[idx] + time[connectedNode]);
			// ������ 0�� �� ��带 ť�� ����
			if (--degree[connectedNode] == 0)
			{
				q.push(connectedNode);
			}
		}		
	}

	// ���
	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << "\n";
	}

	return 0;
}