/// Dance Dance Revolution(DDR)
/// https://www.acmicpc.net/problem/2342
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 99999999;

int N;
int s[5][5]; // s[i][j] = i->j로 발을 옮길 때 드는 힘
vector<int> commands;
// dp[c][i][j] : c번째 지시사항까지 고려했을 때, 왼발이 i에 있고 오른발에 j에 있을 때 드는 최소 힘
int dp[100001][5][5];

int Backtrack(int cur, int left, int right)
{
	if (cur == N - 1)
	{
		return 0;
	}

	if (left != 0 && right != 0 && left == right)
	{
		return MAX;
	}

	if (dp[cur][left][right] != -1)
	{
		return dp[cur][left][right];
	}

	int next = commands[cur + 1];
	// 왼발 옮겼을 때와 오른발 옮겼을 때 중 최소값
	return dp[cur][left][right] = min(Backtrack(cur + 1, next, right) + s[left][next], 
		Backtrack(cur + 1, left, next) + s[right][next]);
}

int main()
{
	commands.push_back(0);
	while (true)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			break;
		}
		commands.push_back(num);
	}
	N = commands.size();

	s[0][1] = s[0][2] = s[0][3] = s[0][4] = 2;
	s[1][1] = s[2][2] = s[3][3] = s[4][4] = 1;
	s[1][2] = s[1][4] = s[2][1] = s[2][3] = s[3][2] = s[3][4] = s[4][1] = s[4][3] = 3;
	s[1][3] = s[2][4] = s[3][1] = s[4][2] = 4;

	memset(dp, -1, sizeof(dp));

	cout << Backtrack(0, 0, 0);

	return 0;
}