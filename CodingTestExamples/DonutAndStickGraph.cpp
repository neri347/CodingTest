/// 도넛과 막대 그래프
/// https://school.programmers.co.kr/learn/courses/30/lessons/258711
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
vector<int> inEdges;
vector<int> outEdges;
vector<vector<int>> graph;
vector<bool> isVisited;
int shape_donut;
int shape_stick;
int shape_8;

int DFS(int cur)
{
	isVisited[cur] = true;
	int degree = graph[cur].size();
	if (degree == 0)
	{
		return INT_MAX;
	}

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (!isVisited[next])
		{
			degree = max(degree, DFS(next));
		}
	}

	return degree;
}

vector<int> solution(vector<vector<int>> edges) {
	vector<int> answer;
	inEdges.resize(1000001, 0);
	outEdges.resize(1000001, 0);
	graph.resize(1000001);
	isVisited.resize(1000001, false);
	int n = 0;

	// 그래프 생성
	for (const auto& edge : edges)
	{
		int start = edge[0];
		int end = edge[1];
		inEdges[end]++;
		outEdges[start]++;
		graph[start].push_back(end);
		n = max({ n, start, end });
	}

	int startVertex = 0;
	for (int i = 1; i <= n; i++)
	{
		// 시작점 찾기
		if (inEdges[i] == 0 && outEdges[i] > 1)
		{
			startVertex = i;
			break;
		}
	}

	for (const auto& vertex : graph[startVertex])
	{
		int degree = DFS(vertex);
		if (degree == 1)
		{
			++shape_donut;
		}
		else if (degree == INT_MAX)
		{
			++shape_stick;
		}
		else
		{
			++shape_8;
		}
	}

	return { startVertex, shape_donut, shape_stick, shape_8 };
}

int main()
{
	vector<vector<int>> edges = { {2, 3},{4, 3},{1, 1},{2, 1} };
	solution(edges);
	return 0;
}