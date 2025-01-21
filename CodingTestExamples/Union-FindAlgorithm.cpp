/// p.411 ����33_������ ���Ͽ�-���ε� �˰��� �����ϱ�
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> ranks;

int Find(int x)
{
	if (x != parent[x])
	{
		int ret = Find(parent[x]);
		// ��� ����
		parent[x] = ret;
		return ret;
	}
	return x;
}

void Union(int x, int y)
{
	int p1 = Find(x);
	int p2 = Find(y);

	if (ranks[p1] == ranks[p2])
	{
		parent[y] = p1;
		ranks[p1]++;
	}
	else
	{
		if (ranks[p1] > ranks[p2])
		{
			parent[y] = p1;
		}
		else
		{
			parent[x] = p2;
		}
	}

}

vector<bool> solution(int k, vector<vector<char>> operations)
{
	vector<bool> answer;
	parent.resize(k);
	ranks.resize(k, 0);
	// �ʱ� �� ������ �θ���� �ڱ� �ڽ��̴�.
	for (int i = 0; i < k; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < operations.size(); ++i)
	{
		char command = operations[i][0];
		int node1 = operations[i][1] - '0';
		int node2 = operations[i][2] - '0';
		if (command == 'u')
		{
			Union(node1, node2);
		}
		else
		{
			answer.push_back(Find(node1) == Find(node2));
		}
	}

	return answer;
}

int main()
{
	//int k = 3;
	int k = 4;
	//vector<vector<char>> operations = { {'u','0','1'}, {'u','1','2'}, {'f','0','2'} };
	vector<vector<char>> operations = { {'u','0','1'}, {'u','2','3'}, {'f','0','1'}, {'f','0','2'} };
	for (auto b : solution(k, operations))
	{
		if (b)
		{
			cout << "true ";
		}
		else
		{
			cout << "false ";
		}
	}
	return 0;
}