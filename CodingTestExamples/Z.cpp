/// Z
/// https://www.acmicpc.net/problem/1074
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, R, C;
int answer;
vector<vector<int>> board;

void Recursive(int x, int y, int sz)
{
	if (x == R && y == C)
	{
		cout << answer;
		return;
	}
	else if (x <= R && y <= C && R < x + sz && C < y + sz)
	{
		// R, C가 해당 사분면 안에 있다면 4 분할 후 탐색
		Recursive(x, y, sz / 2);
		Recursive(x, y + sz / 2, sz / 2);
		Recursive(x + sz / 2, y, sz / 2);
		Recursive(x + sz / 2, y + sz / 2, sz / 2);
	}
	else
	{
		answer += sz * sz;
	}
}

int main()
{
	cin >> N >> R >> C;
	Recursive(0, 0, pow(2, N));
	return 0;
}