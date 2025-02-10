/// ¾ç°ú ´Á´ë
/// https://school.programmers.co.kr/learn/courses/30/lessons/92343
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> nodeInfo;
vector<int> isVisited;
int maxSheep;

void DFS(vector<int> nodes)
{
	int sheepCount = 0;
	int wolfCount = 0;
	for (auto& n : nodes)
	{
		if (nodeInfo[n] == 0)
		{
			++sheepCount;
		}
		else
		{
			++wolfCount;
		}
	}
	if (wolfCount >= sheepCount)
	{
		return;
	}

	maxSheep = max(maxSheep, sheepCount);

	for (int i = 0; i < nodes.size(); i++)
	{
		int currentNode = nodes[i];
		for (int child : graph[currentNode])
		{
			if (isVisited[child])
				continue;
			isVisited[child] = true;
			nodes.push_back(child);
			DFS(nodes);
			nodes.pop_back();
			isVisited[child] = false;
		}
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	nodeInfo = info;
	isVisited.assign(info.size(), false);
	graph.resize(info.size());
	for (auto& v : edges)
	{
		graph[v[0]].push_back(v[1]);
	}

	isVisited[0] = true;
	DFS({ 0 });

	return maxSheep;
}

int main()
{

	return 0;
}