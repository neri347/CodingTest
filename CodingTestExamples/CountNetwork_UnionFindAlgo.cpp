#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> parents;
vector<int> depth;

int FindRoot(int currentNode)
{
	if (parents[currentNode] == currentNode)
	{
		return currentNode;
	}
	int root = FindRoot(parents[currentNode]);
	parents[currentNode] = root;
	return root;
}

void ConnectNetwork(int a, int b)
{
	int root1 = FindRoot(a);
	int root2 = FindRoot(b);

	if (root1 == root2)
		return;

	if (depth[root1] == depth[root2])
	{
		parents[root2] = root1;
		depth[root1]++;
	}
	else
	{
		if (depth[root1] > depth[root2])
		{
			parents[root2] = root1;
		}
		else
		{
			parents[root1] = root2;
		}
	}

}

int solution(int n, vector<vector<int>> computers)
{
	depth.assign(computers.size(), 0);

	// 처음 부모는 자기자신
	for (int i = 0; i < computers.size(); i++)
	{
		parents.push_back(i);
	}

	// 네트워크 연결
	for (int i = 0; i < computers.size(); i++)
	{
		for (int j = 0; j < computers[i].size(); j++)
		{
			if (computers[i][j] == 1)
			{
				ConnectNetwork(i, j);
			}
		}
	}

	// 루트노드 확인
	unordered_set<int> s;
	int ret = 0;
	for (int i = 0; i < computers.size(); i++)
	{
		int root = FindRoot(i);
		if (s.find(root) == s.end())
		{
			s.insert(root);
			++ret;
		}
	}
	return ret;
}

int main()
{
	

	return 0;
}