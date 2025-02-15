/// ���� ���� Ƚ��
/// https://school.programmers.co.kr/learn/courses/30/lessons/389479
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k)
{
	int answer = 0;
	queue<int> q;
	for (int i = 0; i < players.size(); i++)
	{
		// ���� �ð� üũ
		while (!q.empty() && i - q.front() >= k)
		{
			q.pop();
		}

		// ���� �̿��� ���� (n+1) * m�� �̻��̸� ���� ����
		while (players[i] >= (q.size() + 1) * m)
		{
			++answer;
			q.push(i);
		}
	}
	return answer;
}

int main()
{
	/*vector<int> players = { 0,2,3,3,1,2,0,0,0,0,4,2,0,6,0,4,2,13,3,5,10,0,1,5 };
	int m = 3;
	int k = 5;*/
	/*vector<int> players = { 0,0,0,10,0,12,0,15,0,1,0,1,0,0,0,5,0,0,11,0,8,0,0,0 };
	int m = 5;
	int k = 1;*/
	vector<int> players = { 0,0,0,0,0,2,0,0,0,1,0,5,0,2,0,1,0,0,0,0,0,0,0,1 };
	int m = 1;
	int k = 1;
	cout << solution(players, m, k);
	return 0;
}