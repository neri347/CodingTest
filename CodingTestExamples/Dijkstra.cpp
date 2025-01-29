/// p.474 문제 38 다익스트라 알고리즘
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Compare
{
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

// 시작 노드부터 각 노드까지의 최소 비용을 담은 벡터를 반환
vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
	// 그래프 생성
	vector<vector<pair<int, int>>> graph(numNodes);
	for (const auto& [from, to, weight] : edges)
	{
		graph[from].push_back({ to, weight });
	}

	vector<int> distances(numNodes, INT_MAX);
	vector<bool> isVisited(numNodes, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	distances[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int vertex = pq.top().first;
		int currentDistance = pq.top().second;
		pq.pop();

		if (isVisited[vertex])
		{
			continue;
		}
		isVisited[vertex] = true;

		for (auto& [to, weight] : graph[vertex])
		{
			int newWeight = distances[vertex] + weight;
			if (distances[to] > newWeight)
			{
				distances[to] = newWeight;
				pq.push({ to, newWeight });
			}
		}
	}

	return distances;
}

int main()
{
	int start = 0;
	//int numNodes = 3;
	int numNodes = 4;
	vector<tuple<int, int, int>> edges;
	/*tuple<int, int, int> t1(0, 1, 9);
	tuple<int, int, int> t2(0, 2, 3);
	tuple<int, int, int> t3(1, 0, 5);
	tuple<int, int, int> t4(2, 1, 1);
	edges.push_back(t1);
	edges.push_back(t2);
	edges.push_back(t3);
	edges.push_back(t4);*/
	tuple<int, int, int> t1(0, 1, 1);
	tuple<int, int, int> t2(1, 2, 5);
	tuple<int, int, int> t3(2, 3, 1);
	edges.push_back(t1);
	edges.push_back(t2);
	edges.push_back(t3);
	for (int e : solution(start, numNodes, edges))
	{
		cout << e << " ";
	}
	return 0;
}