/// 새로운 게임 2
/// https://www.acmicpc.net/problem/17837
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Piece
{
	int num;
	int x;
	int y;
	int dir; // 우, 좌, 상, 하
};

int N, K;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int board[13][13]; // 0 흰색, 1 빨간색, 2 파란색
vector<int> piecesOnBoard[13][13];
map<int, Piece> pieces;

int GetOppositeDir(int dir)
{
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

bool CheckGameEnd()
{
	for (auto& p : pieces)
	{
		int x = p.second.x;
		int y = p.second.y;
		if (piecesOnBoard[x][y].size() >= 4)
		{
			return true;
		}
	}
	return false;
}

void White(int x, int y, int dir, const vector<int>& movePieces)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// 순서 그대로 옮긴다.
	for (int j = 0; j < movePieces.size(); j++)
	{
		Piece& mp = pieces[movePieces[j]];
		mp.x = nx;
		mp.y = ny;
		piecesOnBoard[nx][ny].push_back(mp.num);
	}

	// 기존 칸에서 말 삭제
	for (int j = 0; j < movePieces.size(); j++)
	{
		piecesOnBoard[x][y].pop_back();
	}
}

void Red(int x, int y, int dir, const vector<int>& movePieces)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// 순서 반대로 옮긴다.
	for (int j = movePieces.size() - 1; j >= 0; j--)
	{
		Piece& mp = pieces[movePieces[j]];
		mp.x = nx;
		mp.y = ny;
		piecesOnBoard[nx][ny].push_back(mp.num);
	}

	// 기존 칸에서 말 삭제
	for (int j = 0; j < movePieces.size(); j++)
	{
		piecesOnBoard[x][y].pop_back();
	}
}

void Blue(int x, int y, int dir, int pieceNum, const vector<int>& movePieces)
{
	dir = GetOppositeDir(dir);
	pieces[pieceNum].dir = dir;
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// 방향 바꾼 후 이동했을 때 파란색 칸이거나 보드 밖으로 나가면 움직이지 않는다.
	if (nx >= 0 && nx < N && ny >= 0 && ny < N)
	{
		if (board[nx][ny] == 0)
		{
			White(x, y, dir, movePieces);
		}
		else if (board[nx][ny] == 1)
		{
			Red(x, y, dir, movePieces);
		}
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int v;
			cin >> v;
			board[i][j] = v;
		}
	}

	for (int i = 0; i < K; i++)
	{
		int x, y, dir;
		cin >> x >> y >> dir;
		pieces[i + 1] = { i + 1, x - 1, y - 1, dir - 1 };
		piecesOnBoard[x - 1][y - 1].push_back(i + 1);
	}

	int answer = -1;
	// 턴이 진행되는 도중 한 칸에 말이 4개 이상 쌓이면 게임 종료
	for (int t = 1; t <= 1000; t++)
	{
		bool flag = false;
		for (auto& p : pieces)
		{
			int num = p.first;
			int x = p.second.x;
			int y = p.second.y;
			int dir = p.second.dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			vector<int> movePieces;
			int index = -1;
			for (int j = 0; j < piecesOnBoard[x][y].size(); j++)
			{
				if (piecesOnBoard[x][y][j] == num)
				{
					index = j;
					break;
				}
			}
			// 이번 말 위의 말도 모두 함께 저장
			for (int j = index; j < piecesOnBoard[x][y].size(); j++)
			{
				movePieces.push_back(piecesOnBoard[x][y][j]);
			}

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (board[nx][ny] == 0) // 하얀 판
				{	
					White(x, y, dir, movePieces);
				}
				else if (board[nx][ny] == 1) // 빨간 판
				{
					Red(x, y, dir, movePieces);
				}
				else // 파란 판
				{
					Blue(x, y, dir, num, movePieces);
				}
			}
			else // 보드판 밖으로 나간다면 파란색과 같다
			{
				Blue(x, y, dir, num, movePieces);
			}

			if (CheckGameEnd())
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			answer = t;
			break;
		}
	}
	cout << answer;

	return 0;
}