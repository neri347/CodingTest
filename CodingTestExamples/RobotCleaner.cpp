/// �κ� û�ұ�
/// https://www.acmicpc.net/problem/14503
#include <iostream>
#include <vector>
using namespace std;

int r, c;
// �� �� �� ��
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

	// �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���
	if (FindDirtyRoom(cx, cy))
	{
		// �ݽð� �������� 90�� ȸ��
		--cdir;
		if (cdir < 0)
		{
			cdir = 3;
		}
		// ȸ���� �������� �� ĭ ���� ���� û�ҵ��� �ʾҴٸ� �� ĭ ����
		int nx = cx + dx[cdir];
		int ny = cy + dy[cdir];
		if (IsDirtyRoom(nx, ny))
		{
			DFS(nx, ny, cdir);
		}
	}
	else
	{
		// �� ĭ ������ �� �ִٸ� ���� �� ���
		int bx = cx - dx[cdir];
		int by = cy - dy[cdir];
		if (IsDirtyRoom(bx, by))
		{
			
		}
	}
}

int main()
{
	// �Է�
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

	// Ǯ��
	DFS(x, y, dir);
	cout << cleanCount;

	return 0;
}