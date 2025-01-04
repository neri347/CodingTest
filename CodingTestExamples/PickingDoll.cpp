#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<stack<int>> boardStacks(board.size());
	stack<int> bucket;

	for (int i = board.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			if (board[i][j] != 0)
			{
				boardStacks[j].push(board[i][j]);
			}
		}
	}

	for (auto index : moves)
	{
		if (!boardStacks[index - 1].empty() && boardStacks[index - 1].top() > 0)
		{
			int doll = boardStacks[index - 1].top();
			boardStacks[index - 1].pop();
			// �ٱ��� ���� ���� �ִ� ������ ������ ���ٸ� �� �� ������ ��������
			if (!bucket.empty() && doll == bucket.top())
			{
				answer += 2;
				bucket.pop();
			}
			else // ������ ���� �ʴٸ� �ٱ��Ͽ� �ִ´�
			{
				bucket.push(doll);
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	cout << solution(board, moves);

	return 0;
}