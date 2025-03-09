/// ���ο� ���� 2
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
	int dir; // ��, ��, ��, ��
};

int N, K;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int board[13][13]; // 0 ���, 1 ������, 2 �Ķ���
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

	// ���� �״�� �ű��.
	for (int j = 0; j < movePieces.size(); j++)
	{
		Piece& mp = pieces[movePieces[j]];
		mp.x = nx;
		mp.y = ny;
		piecesOnBoard[nx][ny].push_back(mp.num);
	}

	// ���� ĭ���� �� ����
	for (int j = 0; j < movePieces.size(); j++)
	{
		piecesOnBoard[x][y].pop_back();
	}
}

void Red(int x, int y, int dir, const vector<int>& movePieces)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// ���� �ݴ�� �ű��.
	for (int j = movePieces.size() - 1; j >= 0; j--)
	{
		Piece& mp = pieces[movePieces[j]];
		mp.x = nx;
		mp.y = ny;
		piecesOnBoard[nx][ny].push_back(mp.num);
	}

	// ���� ĭ���� �� ����
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

	// ���� �ٲ� �� �̵����� �� �Ķ��� ĭ�̰ų� ���� ������ ������ �������� �ʴ´�.
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
	// ���� ����Ǵ� ���� �� ĭ�� ���� 4�� �̻� ���̸� ���� ����
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
			// �̹� �� ���� ���� ��� �Բ� ����
			for (int j = index; j < piecesOnBoard[x][y].size(); j++)
			{
				movePieces.push_back(piecesOnBoard[x][y][j]);
			}

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (board[nx][ny] == 0) // �Ͼ� ��
				{	
					White(x, y, dir, movePieces);
				}
				else if (board[nx][ny] == 1) // ���� ��
				{
					Red(x, y, dir, movePieces);
				}
				else // �Ķ� ��
				{
					Blue(x, y, dir, num, movePieces);
				}
			}
			else // ������ ������ �����ٸ� �Ķ����� ����
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