/// ȸ�ǽ� ����
/// https://www.acmicpc.net/problem/1931
/// ȸ�ǰ� ���� ������ ������ ����
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// �Է�
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
		// ���� ȸ�ǰ� ������ �ð��� �Ȱ��� �ð� Ȥ�� 
		// ������ �ð����� �ڿ� �����ϴ� ȸ�� �� ���� ���� ȸ�Ǹ� ã���� ret++
		if (meetings[i].second >= time)
		{
			++ret;
			time = meetings[i].first;
		}
	}
	printf("%d\n", ret);
	return 0;
}