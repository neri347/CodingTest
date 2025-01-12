/// ��Ʈ�ι̳�
/// https://www.acmicpc.net/problem/14500
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[500][500];

void MakeTetrominoL(vector<vector<vector<pair<int, int>>>>& tetrominos)
{
	vector<vector<pair<int, int>>> blocks;
	vector<pair<int, int>> case1 = { {0,0}, {1,0}, {2,0}, {2,1} };
	vector<pair<int, int>> case2 = { {0,0}, {1,0}, {0,1}, {0,2} };
	vector<pair<int, int>> case3 = { {0,0}, {0,1}, {1,1}, {2,1} };
	vector<pair<int, int>> case4 = { {0,0}, {0,1}, {0,2}, {-1,2} };
	vector<pair<int, int>> case5 = { {0,0}, {0,1}, {-1,1}, {-2,1} };
	vector<pair<int, int>> case6 = { {0,0}, {0,1}, {0,2}, {1,2} };
	vector<pair<int, int>> case7 = { {0,0}, {0,1}, {1,0}, {2,0} };
	vector<pair<int, int>> case8 = { {0,0}, {1,0}, {1,1}, {1,2} };
	blocks.push_back(case1);
	blocks.push_back(case2);
	blocks.push_back(case3);
	blocks.push_back(case4);
	blocks.push_back(case5);
	blocks.push_back(case6);
	blocks.push_back(case7);
	blocks.push_back(case8);
	tetrominos.push_back(blocks);
}

void MakeTetrominoS(vector<vector<vector<pair<int, int>>>>& tetrominos)
{
	vector<vector<pair<int, int>>> blocks;
	vector<pair<int, int>> case1 = { {0,0}, {1,0}, {1,1}, {2,1} };
	vector<pair<int, int>> case2 = { {0,0}, {0,1}, {-1,1}, {-1,2} };
	vector<pair<int, int>> case3 = { {0,0}, {1,0}, {1,-1}, {2,-1} };
	vector<pair<int, int>> case4 = { {0,0}, {0,1}, {1,1}, {1,2} };
	blocks.push_back(case1);
	blocks.push_back(case2);
	blocks.push_back(case3);
	blocks.push_back(case4);
	tetrominos.push_back(blocks);
}

void MakeTetrominoT(vector<vector<vector<pair<int, int>>>>& tetrominos)
{
	vector<vector<pair<int, int>>> blocks;
	vector<pair<int, int>> case1 = { {0,0}, {0,1}, {0,2}, {1,1} };
	vector<pair<int, int>> case2 = { {0,0}, {-1,1}, {0,1}, {1,1} };
	vector<pair<int, int>> case3 = { {0,0}, {1,-1}, {1,0}, {1,1} };
	vector<pair<int, int>> case4 = { {0,0}, {-1,-1}, {0,-1}, {1,-1} };
	blocks.push_back(case1);
	blocks.push_back(case2);
	blocks.push_back(case3);
	blocks.push_back(case4);
	tetrominos.push_back(blocks);
}

void MakeTetrominoI(vector<vector<vector<pair<int, int>>>>& tetrominos)
{
	vector<vector<pair<int, int>>> blocks;
	vector<pair<int, int>> case1 = { {0,0}, {1,0}, {2,0}, {3,0} };
	vector<pair<int, int>> case2 = { {0,0}, {0,1}, {0,2}, {0,3} };	
	blocks.push_back(case1);
	blocks.push_back(case2);
	tetrominos.push_back(blocks);
}

void MakeTetrominoO(vector<vector<vector<pair<int, int>>>>& tetrominos)
{
	vector<vector<pair<int, int>>> blocks;
	vector<pair<int, int>> case1 = { {0,0}, {1,0}, {0,1}, {1,1} };
	blocks.push_back(case1);
	tetrominos.push_back(blocks);
}

bool IsInBoard(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int MaxScore(const vector<vector<vector<pair<int, int>>>>& tetrominos)
{
	int maxScore = 0;
	int sum = 0;

	for (int k = 0; k < tetrominos.size(); ++k)
	{
		// ���� �� �ִ� ��Ʈ���� ��� �������� �˻� -> �� 19����
		for (int t = 0; t < tetrominos[k].size(); ++t)
		{
			// ������ = (i, j)
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < M; ++j)
				{
					sum = 0;
					for (int b = 0; b < 4; ++b) // ��Ʈ�ι̳��� �� ��ϸ��� �˻�(�� 4���)
					{
						int cx = i + tetrominos[k][t][b].first;
						int cy = j + tetrominos[k][t][b].second;
						if (IsInBoard(cx, cy)) // ����� ���� �ȿ� �ִٸ� ���� ������
						{
							sum += board[cx][cy];
						}
						else
						{
							sum = 0;
							break;
						}
					}
					maxScore = max(maxScore, sum);
				}
			}

		}
	}

	return maxScore;
}

int main()
{
	// �Է�
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int score;
			cin >> score;
			board[i][j] = score;
		}
	}

	// ��Ʈ�ι̳� ����
	vector<vector<vector<pair<int, int>>>> tetrominos;
	MakeTetrominoL(tetrominos);
	MakeTetrominoS(tetrominos);
	MakeTetrominoT(tetrominos);
	MakeTetrominoI(tetrominos);
	MakeTetrominoO(tetrominos);

	cout << MaxScore(tetrominos);

	return 0;
}