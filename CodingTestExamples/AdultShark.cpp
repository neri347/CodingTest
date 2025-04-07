/// 어른 상어
/// https://www.acmicpc.net/problem/19237
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 0 = 위, 1 = 아래, 2 = 왼쪽, 3 = 오른쪽

struct Shark
{
	int x, y;
	int dir;
	int priority[4][4];
	bool isAlive = true;
};

int N, M, K;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
set<int> board[20][20];
pair<int, int> smell[20][20];
vector<Shark> sharks;

bool CheckSharks()
{
	for (int i = 2; i < sharks.size(); i++)
	{
		if (sharks[i].isAlive)
		{
			return false;
		}
	}
	return true;
}

void UpdateSmell()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (smell[i][j].first >= 1)
			{
				smell[i][j].second--;
				if (smell[i][j].second <= 0)
				{
					smell[i][j].first = 0;
				}
			}
		}
	}
}

void MoveSharks()
{
	for (int i = 1; i <= M; i++)
	{
		if (!sharks[i].isAlive)
		{
			continue;
		}
		int moveFlag = false;
		int x = sharks[i].x;
		int y = sharks[i].y;
		int dir = sharks[i].dir;
		// 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 이동
		for (int k = 0; k < 4; k++)
		{
			int nd = sharks[i].priority[dir][k];
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (smell[nx][ny].first == 0)
				{
					board[nx][ny].insert(i);
					board[x][y].erase(i);
					sharks[i].x = nx;
					sharks[i].y = ny;
					sharks[i].dir = nd;
					moveFlag = true;
					break;
				}
			}
		}
		if (moveFlag)
		{
			continue;
		}

		// 아무 냄새가 없는 칸이 없다면 자신의 냄새가 있는 칸으로 이동
		for (int k = 0; k < 4; k++)
		{
			int nd = sharks[i].priority[dir][k];
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (smell[nx][ny].first == i)
				{
					board[nx][ny].insert(i);
					board[x][y].erase(i);
					sharks[i].x = nx;
					sharks[i].y = ny;
					sharks[i].dir = nd;
					break;
				}
			}
		}
	}
}

void BanishSharks()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size() > 1)
			{
				int first = *board[i][j].begin();
				auto iter = board[i][j].begin();
				++iter;
				// 숫자 가장 작은 상어 빼고 내쫓기
				for (; iter != board[i][j].end(); ++iter)
				{
					sharks[*iter].isAlive = false;
				}
				board[i][j].clear();
				board[i][j].insert(first);
			}
		}
	}
}

void LeaveSmell()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size() == 1)
			{
				int num = *board[i][j].begin();
				smell[i][j].first = num;
				smell[i][j].second = K;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	sharks.resize(M + 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			if (num >= 1)
			{
				board[i][j].insert(num);
				smell[i][j].first = num;
				smell[i][j].second = K;
				sharks[num].x = i;
				sharks[num].y = j;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		int dir;
		cin >> dir;
		sharks[i + 1].dir = dir - 1;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int p;
				cin >> p;
				sharks[i + 1].priority[j][k] = p - 1;
			}
		}
	}

	int answer = -1;
	for (int i = 1; i <= 1000; i++)
	{
		// 상어 이동
		MoveSharks();
		// 냄새 남은 시간 갱신
		UpdateSmell();
		// 상어 내쫓기
		BanishSharks();
		// 냄새 남기기
		LeaveSmell();
		// 1번 상어만 남았는지 체크
		if (CheckSharks())
		{
			answer = i;
			break;
		}
	}
	cout << answer;
	return 0;
}