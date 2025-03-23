/// 색종이 만들기
/// https://www.acmicpc.net/problem/2630
#include <iostream>
#include <vector>
using namespace std;

int paper[128][128];
int white, blue;

void MakeColorPaper(int x, int y, int len)
{
	int color = paper[x][y];
	bool flag = true;
	for (int i = x; i < x + len; i++)
	{
		for (int j = y; j < y + len; j++)
		{
			if (paper[i][j] != color)
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
	{
		color == 0 ? ++white : ++blue;
	}
	else
	{
		// 색종이 4등분
		MakeColorPaper(x, y, len / 2);
		MakeColorPaper(x, y + len / 2, len / 2);
		MakeColorPaper(x + len / 2, y, len / 2);
		MakeColorPaper(x + len / 2, y + len / 2, len / 2);
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int v;
			cin >> v;
			paper[i][j] = v;
		}
	}
	MakeColorPaper(0, 0, N);
	cout << white << '\n';
	cout << blue << '\n';
	return 0;
}