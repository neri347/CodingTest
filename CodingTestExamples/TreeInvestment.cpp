/// 나무 재테크
/// https://www.acmicpc.net/problem/16235
/// 제한시간이 0.3초로 보통 문제의 1/3수준이므로 제한시간에 유념해야 한다.
/// 불필요한 연산을 줄이고, 알맞은 자료구조를 선택함으로써 해결할 수 있었다.
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M, K;
int board[10][10];
int fertilizer[10][10];
deque<int> trees[10][10];
int dx[8] = { 1,0,0,-1,1,1,-1,-1 };
int dy[8] = { 0,1,-1,0,1,-1,1,-1 };

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int v;
			cin >> v;
			board[i][j] = 5;
			fertilizer[i][j] = v;
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		int x, y, old;
		cin >> x >> y >> old;
		trees[x - 1][y - 1].push_back(old);
	}

	for (int i = 1; i <= K; i++)
	{
		// 봄 = 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
		// 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
		// 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
		// 여름 - 봄에 죽은 나무가 양분으로 변하게 된다. 
		// 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				auto iter = trees[r][c].begin();
				for (; iter != trees[r][c].end(); iter++)
				{
					if (*iter <= board[r][c]) // 양분이 충분하다면 양분을 먹고 나이 증가
					{
						board[r][c] -= *iter;
						*iter += 1;
					}
					else // 양분 없으면 죽음. deque에 나이 순대로 저장되어 있기 때문에 처음 못 먹는 나무 찾으면 뒤에 있는 나무들도 양분 못 먹는다.
					{
						break;
					}
				}

				// 양분 못 먹은 나무들 모두 죽음
				while (iter != trees[r][c].end())
				{
					board[r][c] += *iter / 2;
					iter = trees[r][c].erase(iter);
				}
			}
		}

		// 가을 - 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 
		// 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
		// 겨울 - 각 칸에 추가되는 양분의 양은 A[r][c]이다.
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				auto iter = trees[r][c].begin();
				for (; iter != trees[r][c].end(); iter++)
				{
					if (*iter % 5 == 0)
					{
						for (int k = 0; k < 8; k++)
						{
							int nx = r + dx[k];
							int ny = c + dy[k];
							if (nx >= 0 && nx < N && ny >= 0 && ny < N)
							{
								trees[nx][ny].push_front(1);
							}
						}
					}
				}
				board[r][c] += fertilizer[r][c];
			}
		}
	}

	int answer = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			answer += trees[r][c].size();
		}
	}

	cout << answer;
	return 0;
}