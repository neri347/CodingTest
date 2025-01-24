/// 바이러스
/// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> connected;
bool isVisited[100];
int answer;

void DFS(int cur)
{
	if (isVisited[cur])
	{
		return;
	}

	isVisited[cur] = true;	

	for (int i = 0; i < connected[cur].size(); i++)
	{
		int next = connected[cur][i];
		if (!isVisited[next])
		{
			++answer;
			DFS(next);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	connected.resize(N);
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		connected[start - 1].push_back(end - 1);
		connected[end - 1].push_back(start - 1);
	}

	DFS(0);
	cout << answer;

	return 0;
}