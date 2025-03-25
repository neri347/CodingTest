/// ������
/// https://www.acmicpc.net/problem/1043
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> parent;
vector<int> ranks;

int Find(int node)
{
	if (node != parent[node])
	{
		parent[node] = Find(parent[node]);
	}
	return parent[node];
}

void Union(int x, int y)
{
	int root1 = Find(x);
	int root2 = Find(y);
	if (root1 != root2)
	{
		if (ranks[root1] == ranks[root2])
		{
			parent[root2] = root1;
		}
		else
		{
			if (ranks[root1] > ranks[root2])
			{
				++ranks[root1];
				parent[root2] = root1;
			}
			else
			{
				++ranks[root2];
				parent[root1] = root2;
			}
		}
	}
}

int main()
{
	int N, M; // ����� ��, ��Ƽ�� ��
	cin >> N >> M;
	// �ʱ� ��� ����� �θ�� �ڱ��ڽ�
	for (int i = 0; i <= N; i++)
	{
		parent.push_back(i);
	}
	ranks.resize(N + 1);
	int T; // ������ �ƴ� ����� ��
	cin >> T;
	vector<int> truth;
	// ������ �ƴ� ����� ���� ���̸� ���� �������� �����ش�
	for (int i = 0; i < T; i++)
	{
		int t;
		cin >> t;
		truth.push_back(t);
	}
	for (int i = 1; i < truth.size(); i++)
	{
		Union(truth[0], truth[i]);
	}

	vector<vector<int>> partyInfo;
	for (int i = 0; i < M; i++)
	{
		int c;
		cin >> c;
		vector<int> members;
		// ��Ƽ�� ������ ����� ����
		for (int j = 0; j < c; j++)
		{
			int member;
			cin >> member;
			members.push_back(member);
		}
		partyInfo.push_back(members);

		// ������
		for (int j = 1; j < members.size(); j++)
		{
			Union(members[0], members[j]);
		}
	}

	// ������ ���� ���� ���� �������� �� �ִ� ��Ƽ ã��
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		bool exist = false; // ������ �ƴ� ��� �ִ��� ����
		if (truth.size() > 0)
		{
			int root = Find(truth[0]);
			for (auto& member : partyInfo[i])
			{
				if (Find(member) == root)
				{
					exist = true;
					break;
				}
			}
		}

		if (!exist)
		{
			++answer;
		}
	}
	cout << answer;
	return 0;
}