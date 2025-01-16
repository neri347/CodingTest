/// 주사위 굴리기
/// https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int board[20][20];
int dx[4] = { 0, 0, -1, 1 }; // 동서북남
int dy[4] = { 1, -1, 0, 0 };

int main()
{
	// 입력
	int N, M;
	int cx, cy;
	int orderCnt;
	cin >> N >> M >> cx >> cy >> orderCnt;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int num;
			cin >> num;
			board[i][j] = num;
		}
	}
	vector<int> orders;
	for (int i = 0; i < orderCnt; ++i)
	{
		int num;
		cin >> num;
		orders.push_back(num);
	}

	vector<int> answer;
	// 풀이
	vector<int> dice(6, 0); //0 : 윗면, 1:뒷면, 2:오른쪽면, 3:왼쪽면, 4:앞면, 5:밑면
	for (int i = 0; i < orderCnt; ++i)
	{
		int order = orders[i];
		int nx = cx + dx[order - 1];
		int ny = cy + dy[order - 1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			// 주사위 굴리기
			if (order == 1) // 동
			{
				int top = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = top;
			}
			else if (order == 2) // 서
			{
				int top = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = top;
			}
			else if (order == 3) // 북
			{
				int top = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = top;
			}
			else // 남
			{
				int top = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = top;
			}

			// 이동한 칸에 쓰여있는 수가 0이면, 주사위 밑면 숫자 복사
			if (board[nx][ny] == 0)
			{
				board[nx][ny] = dice[5];
			}
			else	// 0이 아니면 칸에 쓰여있는 수가 주사위 밑면 숫자. 칸은 0이 됨.
			{
				dice[5] = board[nx][ny];
				board[nx][ny] = 0;
			}
			answer.push_back(dice[0]);
			cx = nx;
			cy = ny;
		}
	}

	// 출력
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}