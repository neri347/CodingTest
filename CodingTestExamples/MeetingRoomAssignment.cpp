/// 회의실 배정
/// https://www.acmicpc.net/problem/1931
/// 회의가 빨리 끝나는 순으로 정렬
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int meetingCount = 0;
	scanf("%d", &meetingCount);
	vector<pair<int, int>> meetings;
	for (int i = 0; i < meetingCount; ++i)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		meetings.push_back({end, start});
	}

	sort(meetings.begin(), meetings.end());
	int ret = 1;
	int time = meetings[0].first;
	for (int i = 1; i < meetings.size(); ++i)
	{
		// 현재 회의가 끝나는 시간과 똑같은 시간 혹은 
		// 끝나는 시간보다 뒤에 시작하는 회의 중 가장 빠른 회의를 찾으면 ret++
		if (meetings[i].second >= time)
		{
			++ret;
			time = meetings[i].first;
		}
	}
	printf("%d\n", ret);
	return 0;
}