/// 미로 탈출 명령어
/// https://school.programmers.co.kr/learn/courses/30/lessons/150365
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ROW, COLUMN;
int endX, endY;
string ret = "";
string answer = "";
bool findFlag = false;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
int ch[4] = { 'd', 'l', 'r', 'u' };

void BackTrack(int curX, int curY, int leftCount)
{
	if (findFlag)
	{
		return;
	}
	// 현재 위치와 도착점과의 거리 계산. 거리가 남은 횟수보다 크면 그 위치로는 움직일 수 없다.
	int distance = abs(curX - endX) + abs(curY - endY);
	if (distance > leftCount)
	{
		return;
	}
	// 남은횟수에서 현재 위치와 도착점 사이의 거리를 뺐을 때 홀수이면 도착점으로 도달할 수 없다.
	if ((leftCount - distance) % 2 != 0)
	{
		return;
	}

	// 도착지점에 도착했고 남은 횟수가 없으면 경로를 찾음
	if (leftCount == 0 && curX == endX && curY == endY)
	{
		answer = ret;
		findFlag = true;
		return;
	}

	// 4방향 검사
	for (int i = 0; i < 4; ++i)
	{
		int nx = curX + dx[i];
		int ny = curY + dy[i];
		// 격자에서 나가지 않으면 추가
		if (nx > 0 && nx <= ROW && ny > 0 && ny <= COLUMN)
		{
			ret += ch[i];
			BackTrack(nx, ny, leftCount - 1);
			ret.pop_back();
		}
	}
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
	ROW = n;
	COLUMN = m;
	endX = r;
	endY = c;

	BackTrack(x, y, k);

	return answer == "" ? "impossible" : answer;
}

int main()
{

	return 0;
}