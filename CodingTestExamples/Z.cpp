/// Z
/// https://www.acmicpc.net/problem/1074
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, R, C;
int answer;

void Recur(int x, int y, int sz)
{
	if (x == R && y == C)
	{
		cout << answer;
		return;
	}

	if (x <= R && y <= C && R < x + sz && C < y + sz)
	{
		Recur(x, y, sz / 2);
		Recur(x, y + sz / 2, sz / 2);
		Recur(x + sz / 2, y, sz / 2);
		Recur(x + sz / 2, y + sz / 2, sz / 2);
	}
	else
	{
		answer += sz * sz;
	}
}

int main()
{
	cin >> N >> R >> C;
	Recur(0, 0, pow(2, N));
	return 0;
}