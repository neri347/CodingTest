/// 거짓말
/// https://www.acmicpc.net/problem/1043
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int Find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(int x, int y)
{
	int root1 = Find(x);
	int root2 = Find(y);
	if (root1 != root2)
	{
		parent[root2] = root1;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	parent.assign(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	int T;
	cin >> T;
	int root = 0;
	for (int i = 0; i < T; i++)
	{
		int node;
		cin >> node;
		if (i == 0)
		{
			root = node;
		}
		Union(root, node);
	}

	vector<vector<int>> partyInfo;
	for (int m = 0; m < M; m++)
	{
		int count;
		cin >> count;
		int curRoot = 0;
		vector<int> party;
		for (int c = 0; c < count; c++)
		{
			int num;
			cin >> num;
			party.push_back(num);
			if (c == 0)
			{
				curRoot = num;
			}
			Union(curRoot, num);
		}
		partyInfo.push_back(party);
	}

	int answer = 0;
	for (int m = 0; m < M; m++)
	{
		bool flag = true; // 거짓말할 수 있는 파티인지 여부
		for (auto& member : partyInfo[m])
		{
			if (Find(root) == Find(member))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			++answer;
		}
	}
	cout << answer;
	return 0;
}