/// 서버 증설 횟수
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
		// 서버 시간 체크
		while (!q.empty() && i - q.front() >= k)
		{
			q.pop();
		}

		// 현재 이용자 수가 (n+1) * m명 이상이면 서버 증설
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