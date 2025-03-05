/// ���ÿ�
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
	// dir = 1 ��, dir = 2 �Ʒ�, dir = 3 ������, dir = 4 ����
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
		// ����� ���
		for (int j = 0; j < R; j++)
		{
			if (!board[j][i].empty())
			{
				answer += board[j][i][0].sz;
				board[j][i].pop_back();
				break;
			}
		}
		// ��� �̵�
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

				// �ּ����� �̵��� ���� ������ ����
				// �� ���� �ڸ��� ���� �������� �ǵ��ƿ��� ���ؼ��� 
				// ���Ʒ� ���� ���� (R-1)*2 ĭ��ŭ �̵��ϸ� �ȴ�.
				if (dir == 0 || dir == 1) // �� �Ʒ�
				{
					speed %= (R - 1) * 2;
				}
				else // �¿�
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

		// ���� ĭ ��� ���� ������ ���� ū �� ������ ��� ��Ƹ���
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