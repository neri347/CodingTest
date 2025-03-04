/// 사라지는 발판
/// https://school.programmers.co.kr/learn/courses/30/lessons/92345?language=cpp
/// 미니맥스 알고리즘
/// 내 차례에는 최대 이익이 되는 선택, 상대 차례에는 최소 이익이 되는 선택
/// 항상 A부터 시작.
/// 끝났을 때의 횟수가 짝수라면 내가 지는 것을 의미, 홀수라면 내가 이기는 것을 의미
/// 해당 차례의 경우의 수는 총 4번(상하좌우)
/// 만약 모든 경우의 수 중에서 내가 이기는 경우가 1번이라도 있다면 그 경우를 선택
/// 내가 이길 수 있는 길이 있는데도, 그걸 고르지 않은 것은 최선을 다하지 않은 선택이기 때문
/// 내가 지는 쪽이라면 턴 수가 더 많은 것이 답이 될 것이고,
/// 내가 이기는 쪽이라면 턴 수가 적은 것이 답이 될 것이다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

int DFS(pair<int, int> mine, pair<int, int> yours) // mine = 이번 차례인 사람의 위치, yours = 다음 차례인 사람의 위치
{
	if (map[mine.first][mine.second] == 0)	return 0; // 발판 없어졌다면 0 반환
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = mine.first + dx[i];
		int ny = mine.second + dy[i];
		if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size() && map[nx][ny] == 1)
		{
			map[mine.first][mine.second] = 0;
			int val = DFS(yours, { nx, ny }) + 1;
			map[mine.first][mine.second] = 1;

			// 지금까지 모두 진 경우, 이번에 이겼을 때 -> 이겼을 때 경우 선택
			if (result % 2 == 0 && val % 2 == 1)
			{
				result = val;
			}
			// 지금까지 졌고, 이번에도 졌을 때 -> 최대한 많이 움직인다.
			else if (result % 2 == 0 && val % 2 == 0)
			{
				result = max(result, val);
			}
			// 지금까지 이겼고, 이번에도 이겼을 때 -> 최대한 적게 움직인다.
			else if (result % 2 == 1 && val % 2 == 1)
			{
				result = min(result, val);
			}
		}
	}
	return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	map = board;
	return DFS({ aloc[0], aloc[1] }, { bloc[0], bloc[1] });
}

int main()
{
	vector<vector<int>> board = { {1, 1, 1} ,{1, 1, 1},{1, 1, 1} };
	vector<int> aloc = { 1, 0 };
	vector<int> bloc = { 1, 2 };
	cout << solution(board, aloc, bloc);
	return 0;
}