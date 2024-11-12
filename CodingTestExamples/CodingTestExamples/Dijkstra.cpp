/// p.474 문제 38 다익스트라 알고리즘
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct Compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.first > b.first;
	}
};

// 시작 노드부터 각 노드까지의 최소 비용을 담은 벡터를 반환
vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
	// 그래프 생성
	vector<vector<pair<int, int>>> adjList(numNodes); // to, weight
	for (const auto& [from, to, weight] : edges)
	{
		adjList[from].push_back({ to, weight });
	}

	vector<bool> isVisited(numNodes, false);
	vector<int> costs(numNodes, INT_MAX);
	costs[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // cost, nodeNum
	// 시작 노드 설정
	pq.push({ 0, start });
	// 방문하지 않은 노드 중에서 최소 비용으로 방문할 수 있는 노드 선택
	// 선택된 노드를 거쳐서 갈 수 있는 노드가 있다면,
	// 그 노드의 현재 비용과 선택된 노드를 거쳐가는 비용을 비교해서 후자가 적으면 갱신한다.
	while (!pq.empty())
	{
		int currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();
		if (isVisited[currentNode])
		{
			continue;
		}
		isVisited[currentNode] = true;
		for (const auto& [to, weight] : adjList[currentNode])
		{
			int newWeight = currentCost + weight;
			if (newWeight < costs[to])
			{
				costs[to] = newWeight;
				pq.push({ newWeight, to });
			}
		}
	}

	return costs;
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