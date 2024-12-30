/// 카펫
/// https://school.programmers.co.kr/learn/courses/30/lessons/42842
/// 사각형이 되는 조건 체크
/// 세로의 길이 최소값~최대값 범위를 조건3을 통해 암시해주었다.
/// 사각형의 넓이와 세로의 길이 범위가 주어진 셈이다.
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int total = brown + yellow;
	int maxVertical = sqrt(total);
	// 세로길이는 최소 3, 최대 sqrt(total)
	for (int i = 3; i <= maxVertical; ++i)
	{
		// 현재의 세로길이로 사각형을 만들 수 있는지 확인
		if (total % i == 0)
		{
			int horizon = total / i;
			if (2 * i + 2 * (horizon - 2) == brown)
			{
				return { horizon, i };
			}
		}
	}

	return answer;
}

int main()
{

	return 0;
}