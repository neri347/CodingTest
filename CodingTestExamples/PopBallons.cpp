/// 풍선 터뜨리기
/// https://school.programmers.co.kr/learn/courses/30/lessons/68646
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solution(vector<int> a) {
	if (a.size() <= 2)
	{
		return a.size();
	}

	int answer = 2; // 맨 앞, 맨 뒤 풍선은 무조건 살릴 수 있음
	// i번째 풍선을 살리려면
	// 0 ~ i-1 번째 풍선들을 터뜨려서 남은 풍선과
	// i+1 ~ 맨 뒤 풍선들을 터뜨려서 남은 풍선들과 비교
	// 두 풍선 중 i번째 풍선보다 큰 풍선이 한개라도 있으면
	// i번째 풍선 살릴 수 있음

	// 0번째 ~ i번째 요소까지 최소값 저장
	vector<int> lefts(a.size(), 0);
	int left = INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		left = min(left, a[i]);
		lefts[i] = left;
	}

	// i번째 ~ 맨 마지막 요소까지 최소값 저장
	int right = INT_MAX;
	vector<int> rights(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		right = min(right, a[a.size() - 1 - i]);
		rights[a.size() - 1 - i] = right;
	}

	// 0~i-1까지의 최소값, i+1~끝 까지의 최소값과 i값 비교
	// 둘 중 하나 이상 i값 보다 크면 카운트 한 개 늘린다.
	for (int i = 1; i < a.size() - 1; i++)
	{
		if (lefts[i - 1] > a[i] || rights[i + 1] > a[i])
		{
			++answer;
		}
	}

	return answer;
}

int main()
{

	return 0;
}