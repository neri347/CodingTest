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
bool workFlag = true;

bool IsValid(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

bool IsDirtyRoom(int x, int y)
{
	return IsValid(x, y) && rooms[x][y] == 0;
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
	if (!workFlag)
	{
		return;
	}

	if (rooms[cx][cy] == 0)
	{
		++cleanCount;
		rooms[cx][cy] = 2;
	}

	// �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���
	if (FindDirtyRoom(cx, cy))
	{
		// �ݽð� �������� 90�� ȸ��
		int ndir = cdir - 1;
		if (ndir < 0)
		{
			ndir = 3;
		}
		// ȸ���� �������� �� ĭ ���� ���� û�ҵ��� �ʾҴٸ� �� ĭ ����
		int nx = cx + dx[ndir];
		int ny = cy + dy[ndir];
		if (IsDirtyRoom(nx, ny))
		{
			DFS(nx, ny, ndir);
		}
		else
		{
			DFS(cx, cy, ndir);
		}
	}
	else // �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���
	{
		// �� ĭ ������ �� �ִٸ� ���� �� ���
		int bx = cx - dx[cdir];
		int by = cy - dy[cdir];
		if (IsValid(bx, by) && rooms[bx][by] != 1)
		{
			DFS(bx, by, cdir);
		}
		else
		{
			workFlag = false;
			return;
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