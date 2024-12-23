/// �浹���� ã��
/// https://school.programmers.co.kr/learn/courses/30/lessons/340211
/// ó������ �ִܰ�� ��� �ؼ� BFS �� �� �˾�����...
/// 4. ���� ����Ʈ�� �̵��� ���� �׻� �ִ� ��η� �̵��ϸ� �ִ� ��ΰ� ���� ������ ���, r ��ǥ�� ���ϴ� �̵��� c ��ǥ�� ���ϴ� �̵����� ���� �մϴ�.
/// ��� ������ �о��,
/// r ��ǥ�� �������� r��ǥ�� ���߰�, c ��ǥ�� �������� c��ǥ�� ���߸� �װ� �ִܰ���̴�.
/// �׸��� ���� �߿� ���� ����Ʈ�� ������ �� �ִٴ� ������ �־��µ� ������ ����� �� �о ���߿� �˾�ë��..
/// ������ ����� �о�� �����ϴ� ������ �⸣��.
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<int, map<pair<int, int>, int>> countMap;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	int answer = 0;
	// �κ� ������ �ִܰ�� ���Ϳ� ���� [y,x]
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