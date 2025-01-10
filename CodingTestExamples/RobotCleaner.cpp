/// 로봇 청소기
/// https://www.acmicpc.net/problem/14503
#include <iostream>
#include <vector>
using namespace std;

int r, c;
// 북 동 남 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int rooms[51][51];
int cleanCount;

bool IsDirtyRoom(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c && rooms[x][y] == 0;
}

bool FindDirtyRoom(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsDirtyRoom(nx, ny))
		{
			return true;
		}
	}
	return false;
}

void DFS(int cx, int cy, int cdir)
{
	if (rooms[cx][cy] == 0)
	{
		++cleanCount;
		rooms[cx][cy] = 2;
	}

	// 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
	if (FindDirtyRoom(cx, cy))
	{
		// 반시계 방향으로 90도 회전
		--cdir;
		if (cdir < 0)
		{
			cdir = 3;
		}
		// 회전한 방향으로 한 칸 앞의 방이 청소되지 않았다면 한 칸 전진
		int nx = cx + dx[cdir];
		int ny = cy + dy[cdir];
		if (IsDirtyRoom(nx, ny))
		{
			DFS(nx, ny, cdir);
		}
	}
	else
	{
		// 한 칸 후진할 수 있다면 후진 후 재귀
		int bx = cx - dx[cdir];
		int by = cy - dy[cdir];
		if (IsDirtyRoom(bx, by))
		{
			
		}
	}
}

int main()
{
	// 입력
	cin >> r >> c;
	int x, y, dir;
	cin >> x >> y >> dir;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int temp;
			cin >> temp;
			rooms[i][j] = temp;
		}
	}

	// 풀이
	DFS(x, y, dir);
	cout << cleanCount;

	return 0;
}