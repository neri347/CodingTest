/// µå·¡°ï Ä¿ºê
/// https://www.acmicpc.net/problem/15685
#include <iostream>
#include <vector>
using namespace std;

bool map[101][101];

void DrawLine(int& x, int& y, int dir)
{
	if (dir == 0) // ¿ì
	{
		x++;
	}
	else if (dir == 1) // À§
	{
		y--;
	}
	else if (dir == 2) // ¿Þ
	{
		x--;
	}
	else // ¾Æ·¡
	{
		y++;		
	}

	if (x >= 0 && x < 101 && y >= 0 && y < 101)
	{
		map[x][y] = true;
	}
}

void DFS(int x, int y, vector<int>& dirs, int curGen, int maxGen)
{
	if (curGen > maxGen)
	{
		return;
	}

	vector<int> temp = dirs;
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		int newDir = (temp[i] + 1) % 4;
		dirs.push_back(newDir);
	}

	for (int i = dirs.size() / 2; i < dirs.size(); i++)
	{
		DrawLine(x, y, dirs[i]);
	}

	DFS(x, y, dirs, curGen + 1, maxGen);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, dir, maxGen;
		cin >> x >> y >> dir >> maxGen;

		map[x][y] = true;
		DrawLine(x, y, dir);
		vector<int> dirs;
		dirs.push_back(dir);
		DFS(x, y, dirs, 1, maxGen);
	}

	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
			{
				++answer;
			}
		}
	}

	cout << answer;
	return 0;
}