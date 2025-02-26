/// 사다리 조작
/// https://www.acmicpc.net/problem/15684
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N; // 세로선
int M; // 가로선
int H; // 가로선 위치 개수
bool ladder[31][11];

bool IsValid()
{
	for (int i = 1; i <= N; i++)
	{
		int pos = i;
		for (int j = 1; j <= H; j++)
		{
			if (ladder[j][pos]) // 오른쪽으로 이동
			{
				pos++;
			}
			else if (ladder[j][pos - 1]) // 왼쪽으로 이동
			{
				pos--;
			}
		}
		if (pos != i)
		{
			return false;
		}
	}
	return true;
}

void Backtrack(int count, int maxDepth)
{
	if (maxDepth == count)
	{
		if (IsValid())
		{
			cout << count;
			exit(0);
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			// 양 옆에 사다리 없으면 사다리 놓을 수 있다.
			if (ladder[j][i] || ladder[j][i - 1] || ladder[j][i + 1])
			{
				continue;
			}
			ladder[j][i] = true;
			Backtrack(count + 1, maxDepth);
			ladder[j][i] = false;
			while (!ladder[j][i - 1] && !ladder[j][i + 1]) j++; // 행 스킵. 주변에 사다리 없으면 j 위치에 사다리 놓더라도 그 위에 사다리 놓은것과 같은 결과가 나올 수 밖에 없다.
		}
	}
}

int main()
{
	cin >> N >> M >> H;
	vector<vector<int>> nomi(M);
	for (int i = 0; i < M; i++)
	{
		int row, column;
		cin >> row >> column;
		ladder[row][column] = true;
	}

	for (int i = 0; i <= 3; i++) // i는 놓을 사다리 개수. 최대 사다리 3개까지 놓을 수 있다.
	{
		Backtrack(0, i);
	}

	cout << -1;
	return 0;
}