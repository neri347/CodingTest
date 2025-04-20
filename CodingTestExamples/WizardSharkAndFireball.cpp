/// 마법사 상어와 파이어볼
/// https://www.acmicpc.net/problem/20056
#include <iostream>
#include <vector>
using namespace std;

struct Fireball
{
	int x;
	int y;
	int m;
	int s;
	int d;
};

vector<Fireball> board[50][50];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<Fireball> fireballs;
	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireballs.push_back({ r - 1,c - 1,m,s,d });
	}

	for (int k = 0; k < K; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j].clear();
			}
		}
		// 파이어볼 이동
		// 자신의 방향 d로 s만큼 이동한다.
		for (auto& f : fireballs)
		{
			int move = f.s % N;
			int x = f.x + dx[f.d] * move;
			int y = f.y + dy[f.d] * move;
			if (x < 0)
			{
				x += N;
			}
			if(x >= N)
			{
				x -= N;
			}
			if (y < 0)
			{
				y += N;
			}
			if (y >= N)
			{
				y -= N;
			}
			f.x = x;
			f.y = y;
			board[x][y].push_back(f);
		}
		fireballs.clear();
		// 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
		//	같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
		//	파이어볼은 4개의 파이어볼로 나누어진다.
		//	나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
		//	질량은 ⌊(합쳐진 파이어볼 질량의 합) / 5⌋이다.
		//	속력은 ⌊(합쳐진 파이어볼 속력의 합) / (합쳐진 파이어볼의 개수)⌋이다.
		//	합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
		//	질량이 0인 파이어볼은 소멸되어 없어진다.
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j].size() == 1)
				{
					fireballs.push_back(board[i][j][0]);
					continue;
				}
				if (board[i][j].size() >= 2)
				{
					int sm = 0;
					int ss = 0;
					int sc = board[i][j].size();
					int dir = board[i][j][0].d % 2;
					bool dirSameFlag = true;
					for (int f = 0; f < board[i][j].size(); f++)
					{
						sm += board[i][j][f].m;
						ss += board[i][j][f].s;
						if (dirSameFlag && dir != (board[i][j][f].d % 2))
						{
							dirSameFlag = false;
						}
					}

					int nm = sm / 5;
					int ns = ss / sc;
					if (nm == 0)
					{
						continue;
					}
					if (dirSameFlag)
					{
						// 방향은 0,2,4,6
						for (int d = 0; d < 4; d++)
						{
							fireballs.push_back({ i, j, nm, ns, d * 2 });
						}
					}
					else
					{
						// 방향은 1,3,5,7
						for (int d = 0; d < 4; d++)
						{
							fireballs.push_back({ i, j, nm, ns, d * 2 + 1 });
						}
					}
				}
			}
		}
	}

	int answer = 0;
	for (auto& f : fireballs)
	{
		answer += f.m;
	}
	cout << answer;
	return 0;
}