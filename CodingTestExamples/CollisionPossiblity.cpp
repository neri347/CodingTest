/// 충돌위험 찾기
/// https://school.programmers.co.kr/learn/courses/30/lessons/340211
/// 처음에는 최단경로 라고 해서 BFS 인 줄 알았으나...
/// 4. 다음 포인트로 이동할 때는 항상 최단 경로로 이동하며 최단 경로가 여러 가지일 경우, r 좌표가 변하는 이동을 c 좌표가 변하는 이동보다 먼저 합니다.
/// 라는 조건을 읽어보니,
/// r 좌표를 도착점의 r좌표에 맞추고, c 좌표를 도착점의 c좌표에 맞추면 그게 최단경로이다.
/// 그리고 조건 중에 여러 포인트를 지나갈 수 있다는 조건이 있었는데 문제를 제대로 안 읽어서 나중에 알아챘다..
/// 문제를 제대로 읽어보고 이해하는 습관을 기르자.
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<int, map<pair<int, int>, int>> countMap;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	int answer = 0;
	// 로봇 각각의 최단경로 벡터에 저장 [y,x]
	for (int i = 0; i < routes.size(); ++i)
	{
		int second = 0;
		int startPointX = points[routes[i][0] - 1][0];
		int startPointY = points[routes[i][0] - 1][1];
		countMap[second][{startPointX, startPointY}]++;

		for (int j = 1; j < routes[i].size(); ++j)
		{
			int endPointX = points[routes[i][j] - 1][0];
			int endPointY = points[routes[i][j] - 1][1];

			while (true)
			{
				if (startPointX == endPointX)
				{
					if (startPointY == endPointY)
					{
						break;
					}
					else if (startPointY < endPointY)
					{
						++startPointY;
					}
					else
					{
						--startPointY;
					}
				}
				else if (startPointX < endPointX)
				{
					++startPointX;
				}
				else
				{
					--startPointX;
				}
				countMap[++second][{startPointX, startPointY}]++;
			}
		}
	}

	for (const auto& [key, innerMap] : countMap)
	{
		for (const auto& [pairKey, value] : innerMap)
		{
			if (value > 1)
			{
				++answer;
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> points = { {3,2},{6,4},{4,7},{1,4} };
	vector<vector<int>> routes = { {4,2,},{1,3},{2,4} };
	cout << solution(points, routes);
	return 0;
}