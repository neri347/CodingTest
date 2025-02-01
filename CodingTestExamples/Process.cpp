/// ���μ���
/// https://school.programmers.co.kr/learn/courses/30/lessons/42587
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct s
{
	int priority;
	int location;
};

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<s> q;
	for (int i = 0; i < priorities.size(); i++)
	{
		q.push({ priorities[i], i });
	}
	// �������� ����
	sort(priorities.begin(), priorities.end(), [](int a, int b) { return a > b; });
	
	while (true)
	{
		s fs = q.front();
		q.pop();
		// �ֿ켱������� ť�� �� �ڿ� �ٽ� ���� �ʴ´�
		// �ֿ켱�����̰� ã���� �ϴ� ��ġ�� �ִ� ���μ����� ã�Ҵٸ� �ߴ�
		if (priorities[answer] == fs.priority)
		{
			++answer;
			if (fs.location == location)
			{
				break;
			}
			continue;
		}
		q.push(fs);
	}
}

int main()
{
	vector<int> priorities = { 1,1,9,1,1,1 };
	int location = 0;
	solution(priorities, location);
	return 0;
}