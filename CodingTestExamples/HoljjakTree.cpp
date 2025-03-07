/// 홀짝 트리
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

		// 노드숫자와 노드자식개수를 더해서 짝수면 홀짝노드
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

		// 노드숫자와 노드자식개수를 더해서 홀수면 역홀짝노드
		if ((node + children_cnt_if_not_root) % 2 == 1)
		{
			if (holjjak_root_chance)
			{
				--holjjak_root_chance; // 홀짝노드의 루트가 될 가능성 있음
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
		if (holjjak_root_chance) // 홀짝노드의 루트가 없으면 홀짝트리가 될 수 없다
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

	// 모든 노드 순회해서 홀짝트리/역홀짝트리 여부 체크
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