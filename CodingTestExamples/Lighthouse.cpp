/// µî´ë
/// https://school.programmers.co.kr/learn/courses/30/lessons/133500
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> light;
int answer;

void DFS(int index, int prev)
{
	for (auto& house : graph[index])
	{
		if (house == prev)   continue;
		DFS(house, index);

		if (!light[house] && !light[index])
		{
			light[index] = true;
			++answer;
		}
	}
}

int solution(int n, vector<vector<int>> lighthouse) {
	graph.resize(n);
	light.assign(n, false);
	for (auto& vec : lighthouse)
	{
		int from = vec[0] - 1;
		int to = vec[1] - 1;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	DFS(0, 0);

	return answer;
}

int main()
{

	return 0;
}