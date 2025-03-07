/// Ȧ¦ Ʈ��
/// https://school.programmers.co.kr/learn/courses/30/lessons/388354
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> isVisited;

pair<bool, bool> BFS(int start)
{
	queue<int> q;
	q.push(start);
	isVisited[start] = true;

	bool is_holjjak = true;
	int holjjak_root_chance = 1;

	bool is_reverse_holjjak = true;
	int reverse_holjjak_root_chance = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		int children_cnt_if_root = graph[node].size();
		int children_cnt_if_not_root = graph[node].size() - 1;

		// �����ڿ� ����ڽİ����� ���ؼ� ¦���� Ȧ¦���
		if ((node + children_cnt_if_not_root) % 2 == 0)
		{
			if (reverse_holjjak_root_chance)
			{
				--reverse_holjjak_root_chance;
			}
			else
			{
				is_reverse_holjjak = false;
			}
		}

		// �����ڿ� ����ڽİ����� ���ؼ� Ȧ���� ��Ȧ¦���
		if ((node + children_cnt_if_not_root) % 2 == 1)
		{
			if (holjjak_root_chance)
			{
				--holjjak_root_chance; // Ȧ¦����� ��Ʈ�� �� ���ɼ� ����
			}
			else
			{
				is_holjjak = false;
			}
		}

		for (int next : graph[node])
		{
			if (!isVisited[next])
			{
				isVisited[next] = true;
				q.push(next);
			}
		}
	}

	if (is_holjjak)
	{
		if (holjjak_root_chance) // Ȧ¦����� ��Ʈ�� ������ Ȧ¦Ʈ���� �� �� ����
		{
			is_holjjak = false;
		}
	}

	if (is_reverse_holjjak)
	{
		if (reverse_holjjak_root_chance)
		{
			is_reverse_holjjak = false;
		}
	}

	return { is_holjjak, is_reverse_holjjak };
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
	vector<int> answer = { 0, 0 };
	graph.resize(1000000 + 1);
	isVisited.assign(1000000 + 1, false);
	for (int i = 0; i < edges.size(); i++)
	{
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}

	// ��� ��� ��ȸ�ؼ� Ȧ¦Ʈ��/��Ȧ¦Ʈ�� ���� üũ
	for (int node : nodes)
	{
		if (!isVisited[node])
		{
			auto result = BFS(node);
			if (result.first)
			{
				++answer[0];
			}
			if (result.second)
			{
				++answer[1];
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> nodes = { 2, 6, 4, 3, 11, 9 };
	vector <vector<int>> edges = { {9, 11} ,{2, 3},{6, 3},{3, 4} };
	for (int e : solution(nodes, edges))
	{
		cout << e << " ";
	}
	return 0;
}