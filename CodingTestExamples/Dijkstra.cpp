/// p.474 ���� 38 ���ͽ�Ʈ�� �˰���
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct Compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};
	

// ���� ������ �� �������� �ּ� ����� ���� ���͸� ��ȯ
vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
	// �׷��� ����
	vector<vector<pair<int, int>>> adjList(numNodes);
	for (const auto& [from, to, weight] : edges)
	{
		adjList[from].push_back({ to, weight });
	}

	vector<int> distances(numNodes, INT_MAX);
	vector<bool> isVisited(numNodes, false);
	distances[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int node = pq.top().first;
		int dist = pq.top().second;
		pq.pop();

		if (isVisited[node])
		{
			continue;
		}

		isVisited[node] = true;

		// �ش� ������ ����� ���� �Ÿ� ����
		for (const auto& [to, weight] : adjList[node])
		{
			// �ش� ������ ���� ����� �������� ���� �Ÿ� ���
			int nd = dist + weight;
			if (nd < distances[to])
			{
				distances[to] = nd;
				pq.push({ to, nd });
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