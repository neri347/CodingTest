#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

pair<int, int> FindEmptyPosition()
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				return { j, i }; // row, column
			}
		}
	}
	return { -1, -1 };
}

bool IsValid(int row, int column, int desired)
{
	// 행 검사
	for (int i = 0; i < board[column].size(); i++)
	{
		if (board[column][i] == desired)
		{
			return false;
		}
	}
	// 열 검사
	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][row] == desired)
		{
			return false;
		}
	}
	// 3x3 검사
	// 0,1,2 / 3,4,5 / 6,7,8
	// [0][2] => [0][0] [0][1] [0][2]
	//			 [1][0] [1][1] [1][2]
	//			 [2][0] [2][1] [2][2]
	//----------------
	// [4][3] => [3][3] [3][4] [3][5]
	//			 [4][3] [4][4] [4][5]
	//			 [5][3] [5][4] [5][5]
	// [1][8] => [0][6] [0][7] [0][8]
	//			 [1][6] [1][7] [1][8]
	//			 [2][6] [2][7] [2][8]
	int r = (row / 3) * 3;
	int c = (column / 3) * 3;
	for (int i = c; i < c + 3; i++)
	{
		for (int j = r; j < r + 3; j++)
		{
			if (board[i][j] == desired)
			{
				return false;
			}
		}
	}
	return true;
}

void Solve()
{
	// 빈칸 찾아서 들어갈 만한 숫자 넣어서 재귀함수 돌리기
	// 재귀함수 돌리다가 다 완성되지 않았는데 빈칸에 들어갈만한 숫자가 없다면 빠져나와서 다시 빈칸으로 만들어줌
	// 다 완성되었다면 리턴
	pair<int, int> emptyPos = FindEmptyPosition();
	if (emptyPos.first == -1)
	{
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (IsValid(emptyPos.first, emptyPos.second, i))
		{
			board[emptyPos.second][emptyPos.first] = i;
			Solve();
			if (FindEmptyPosition().first == -1)
			{
				return;
			}
			board[emptyPos.second][emptyPos.first] = 0;
		}
	}
}

vector<vector<int>> solution(vector<vector<int>> input_board)
{
	board = input_board;
	Solve();
	return board;
}

int main()
{
	vector<int> v1 = { 5,3,0,0,7,0,0,0,0 };
	vector<int> v2 = { 6,0,0,1,9,5,0,0,0 };
	vector<int> v3 = { 0,9,8,0,0,0,0,6,0 };
	vector<int> v4 = { 8,0,0,0,6,0,0,0,3 };
	vector<int> v5 = { 4,0,0,8,0,3,0,0,1 };
	vector<int> v6 = { 7,0,0,0,2,0,0,0,6 };
	vector<int> v7 = { 0,6,0,0,0,0,2,8,0 };
	vector<int> v8 = { 0,0,0,4,1,9,0,0,5 };
	vector<int> v9 = { 0,0,0,0,8,0,0,7,9 };

	vector<vector<int>> input_board;
	input_board.push_back(v1);
	input_board.push_back(v2);
	input_board.push_back(v3);
	input_board.push_back(v4);
	input_board.push_back(v5);
	input_board.push_back(v6);
	input_board.push_back(v7);
	input_board.push_back(v8);
	input_board.push_back(v9);
	
	for (const auto& vec : solution(input_board))
	{
		for (auto e : vec)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}