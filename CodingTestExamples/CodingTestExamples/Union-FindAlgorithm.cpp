#include <iostream>
#include <vector>
using namespace std;

vector<int> parents;
vector<int> ranks;

int Find(int n)
{
	if (n == parents[n])
	{
		return n;
	}
	parents[n] = Find(parents[n]);
	return parents[n];
}

void Union(int a, int b)
{
	// a와 b의 루트 찾기
	int root1 = Find(a);
	int root2 = Find(b);
	// 루트들의 랭크 비교
	// 랭크 같으면 앞의 것 랭크로
	// 랭크 다르면 랭크값 큰 것으로
	if (root1 != root2)
	{
		if (ranks[root1] == ranks[root2])
		{
			parents[root2] = root1;
			++ranks[root2];
		}
		else if (ranks[root1] > ranks[root2])
		{
			parents[root2] = root1;
		}
		else
		{
			parents[root1] = root2;
		}
	}	
}

vector<bool> solution(int k, vector<vector<char>> operations)
{
	vector<bool> answer;
	for (int i = 0; i < k; i++)
	{
		parents.push_back(i);
		ranks.push_back(0);
	}

	for (int i = 0; i < operations.size(); i++)
	{
		if (operations[i][0] == 'u')
		{
			int v1 = operations[i][1] - '0';
			int v2 = operations[i][2] - '0';
			Union(v1, v2);
		}
		else
		{
			int v1 = operations[i][1] - '0';
			int v2 = operations[i][2] - '0';
			answer.push_back(Find(v1) == Find(v2));
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