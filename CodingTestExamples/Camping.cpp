/// 캠핑
/// https://school.programmers.co.kr/learn/courses/30/lessons/1833
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int Count(vector<vector<int>>& data)
{
	int ret = 0;
	sort(data.begin(), data.end());

	for (int i = 0; i < data.size(); i++)
	{
		int x1 = data[i][0];
		int y1 = data[i][1];
		int yMin = INT_MAX;
		int yMax = INT_MAX;
		int curX = x1;
		for (int j = i + 1; j < data.size(); j++)
		{
			int x2 = data[j][0];
			int y2 = data[j][1];

			if (x2 <= x1 || y2 <= y1)    continue;

			if (yMin == INT_MAX)
			{
				yMin = y2;
				curX = x2;
			}
			else if (y2 <= yMin)
			{
				yMax = yMin;
				yMin = y2;
				curX = x2;
			}
			else if (curX != x2 || y2 > yMax)
			{
				// 설치된 텐트 안의 범위에 다른 쐐기가 있다면 개수에 반영하지 않는다.
				ret--;
			}
			ret++;
		}
	}
	return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
	int answer = 0;
	// 특정 쐐기의 오른쪽 밑 확인
	answer += Count(data);
	// 특정 쐐기의 오른쪽 위 확인
	for (auto& vec : data)
	{
		vec[0] *= -1;
	}
	answer += Count(data);

	return answer;
}

int main()
{
	vector<vector<int>> vec = { {0, 0}, {1, 1}, {0, 2}, {2, 0} };
	
	return 0;
}