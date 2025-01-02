/// 가장 큰 정사각형 찾기
/// https://school.programmers.co.kr/learn/courses/30/lessons/12905
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
	int sideLen = 0;
	vector<vector<int>> lengths(board.size(), vector<int>(board[0].size(), 0));
	// 맨 윗줄, 맨 왼쪽 줄 채우기
	for (int i = 0; i < board[0].size(); ++i)
	{
		lengths[0][i] = board[0][i];
		sideLen = max(sideLen, lengths[0][i]);
	}
	for (int i = 1; i < board.size(); ++i)
	{
		lengths[i][0] = board[i][0];
	}
	// [1][1] ~
	for (int i = 1; i < board.size(); ++i)
	{
		for (int j = 1; j < board[i].size(); ++j)
		{
			if (board[i][j] == 0)
				lengths[i][j] = 0;
			else
			{
				int diagonal = lengths[i - 1][j - 1];
				int up = lengths[i - 1][j];
				int left = lengths[i][j - 1];
				lengths[i][j] = min({ diagonal, up, left }) + 1;
			}
			sideLen = max(sideLen, lengths[i][j]);
		}
	}

	return sideLen * sideLen;
}

int main()
{

	return 0;
}