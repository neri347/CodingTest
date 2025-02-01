/// 프로세스
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
	// 내림차순 정렬
	sort(priorities.begin(), priorities.end(), [](int a, int b) { return a > b; });
	
	while (true)
	{
		s fs = q.front();
		q.pop();
		// 최우선순위라면 큐의 맨 뒤에 다시 넣지 않는다
		// 최우선순위이고 찾고자 하는 위치에 있는 프로세스를 찾았다면 중단
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