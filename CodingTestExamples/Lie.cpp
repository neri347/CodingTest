/// 거짓말
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
	int N, M; // 사람의 수, 파티의 수
	cin >> N >> M;
	// 초기 모든 노드의 부모는 자기자신
	for (int i = 0; i <= N; i++)
	{
		parent.push_back(i);
	}
	ranks.resize(N + 1);
	int T; // 진실을 아는 사람의 수
	cin >> T;
	vector<int> truth;
	// 진실을 아는 사람이 여러 명이면 같은 집합으로 합쳐준다
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
		// 파티에 참가한 사람들 저장
		for (int j = 0; j < c; j++)
		{
			int member;
			cin >> member;
			members.push_back(member);
		}
		partyInfo.push_back(members);

		// 합집합
		for (int j = 1; j < members.size(); j++)
		{
			Union(members[0], members[j]);
		}
	}

	// 저장한 집합 정보 토대로 거짓말할 수 있는 파티 찾기
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		bool exist = false; // 진실을 아는 사람 있는지 여부
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