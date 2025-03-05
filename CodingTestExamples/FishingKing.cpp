/// 낚시왕
/// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark
{
	int r;
	int c;
	int speed;
	int dir;
	int sz;
};

vector<Shark> board[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool Cmp(const Shark& a, const Shark& b)
{
	return a.sz > b.sz;
}

int GetOppositeDir(int dir)
{
	// dir = 1 위, dir = 2 아래, dir = 3 오른쪽, dir = 4 왼쪽
	if (dir == 0)
	{
		return 1;
	}
	else if (dir == 1)
	{
		return 0;
	}
	else if (dir == 2)
	{
		return 3;
	}
	else
	{
		return 2;
	}
}

void SharkEating(int x, int y, vector<Shark>& sharks)
{
	if (sharks.size() == 1)
	{
		board[x][y].push_back(sharks[0]);
	}
	else
	{
		sort(sharks.begin(), sharks.end(), Cmp);
		board[x][y].push_back(sharks[0]);
	}
}

int main()
{
	int R, C, M;
	cin >> R >> C >> M;
	if (M == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		board[r - 1][c - 1].push_back({ r - 1,c - 1,s,d - 1,z });
	}

	int answer = 0;
	for (int i = 0; i < C; i++)
	{
		// 물고기 잡기
		for (int j = 0; j < R; j++)
		{
			if (!board[j][i].empty())
			{
				answer += board[j][i][0].sz;
				board[j][i].pop_back();
				break;
			}
		}
		// 상어 이동
		vector<vector<vector<Shark>>> temp(R, vector<vector<Shark>>(C));
		for(int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{			
				if (board[r][c].empty())	continue;
				Shark shark = board[r][c][0];
				board[r][c].pop_back();
				int x = r;
				int y = c;
				int speed = shark.speed;
				int dir = shark.dir;
				int size = shark.sz;

				// 최소한의 이동을 위해 나머지 연산
				// 상어가 원래 자리에 원래 방향으로 되돌아오기 위해서는 
				// 위아래 방향 기준 (R-1)*2 칸만큼 이동하면 된다.
				if (dir == 0 || dir == 1) // 위 아래
				{
					speed %= (R - 1) * 2;
				}
				else // 좌우
				{
					speed %= (C - 1) * 2;
				}

				while (speed > 0)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C)
					{
						dir = GetOppositeDir(dir);
						nx = x + dx[dir];
						ny = y + dy[dir];
					}
					speed--;
					x = nx;
					y = ny;
				}
				shark.r = x;
				shark.c = y;
				shark.dir = dir;

				temp[x][y].push_back(shark);
			}
		}

		// 같은 칸 상어 여러 마리면 가장 큰 상어가 나머지 상어 잡아먹음
		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				if (temp[r][c].empty())	continue;
				SharkEating(r, c, temp[r][c]);
			}
		}
	}
	cout << answer;
	return 0;
}