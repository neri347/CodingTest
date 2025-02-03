/// ��ũ ��Ʈ�ѷ�
/// https://school.programmers.co.kr/learn/courses/30/lessons/42627
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Task
{
	int num;
	int requestTime;
	int takeTime;
	int startTime; // �۾� ���� �ð�
};

struct Cmp
{
	bool operator()(Task t1, Task t2)
	{
		if (t1.takeTime == t2.takeTime)
		{
			if (t1.requestTime == t2.requestTime)
			{
				return t1.num > t2.num;
			}
			return t1.requestTime > t2.requestTime;
		}
		return t1.takeTime > t2.takeTime;
	}
};

struct JobCmp
{
	bool operator()(Task t1, Task t2)
	{
		// ��û�ð� �̸� ������ ����
		return t1.requestTime > t2.requestTime;
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	priority_queue<Task, vector<Task>, JobCmp> jobQueue;
	for (int i = 0; i < jobs.size(); i++)
	{
		jobQueue.push({ i, jobs[i][0], jobs[i][1], -1 });
	}
	priority_queue<Task, vector<Task>, Cmp> pq;
	vector<pair<int, int>> times(jobs.size()); // �� �۾��� <��û�ð�, �۾�����ð�>

	Task curTask; // ���� �۾� ���� �۾�
	bool isTasking = false;
	int second = 0;
	while (!jobQueue.empty() || !pq.empty())
	{
		while (!jobQueue.empty())
		{
			// ����ð��� �۾� ��û�ð����� �� �Ǿ����� pq�� �� �۾��� ��� �ִ´�
			auto t = jobQueue.top();
			if (second >= t.requestTime)
			{
				jobQueue.pop();
				pq.push(t);
			}
			else
			{
				break;
			}
		}

		// �۾� ���̶��
		if (isTasking) 
		{
			// �۾� �Ϸ��ߴ��� Ȯ��
			if (second == curTask.startTime + curTask.takeTime)
			{
				isTasking = false;
				times[curTask.num] = { curTask.requestTime, second };
			}
		}

		// ���� �۾� ���� �۾� ������ �ֿ켱���� �۾� ����
		if (!isTasking)
		{
			if (!pq.empty())
			{
				auto t = pq.top();
				t.startTime = second;
				curTask = t;
				isTasking = true;
				pq.pop();
			}
		}
		
		++second;
	}

	// ������ �۾�
	times[curTask.num] = { curTask.requestTime, curTask.startTime + curTask.takeTime };

	int sum = 0;
	for (int i = 0; i < times.size(); i++)
	{
		cout << i << ": " << times[i].first << " " << times[i].second << endl;
		sum += (times[i].second - times[i].first);
	}
	answer = sum / times.size();

	return answer;
}

int main()
{
	//vector<vector<int>> jobs = { {0,3},{1,9},{3,5} };
	vector<vector<int>> jobs = { {10,5},{2,3},{5,3},{0,2} };
	cout << solution(jobs);
	return 0;
}