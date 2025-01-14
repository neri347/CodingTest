/// 아기 상어
/// https://www.acmicpc.net/problem/16236

// 상어의 처음 크기는 2이고, 1초에 한 칸씩 이동
// 자신보다 작은 물고기만 먹을 수 있다.
// 자신과 같은 크기의 물고기가 있는 자리를 지나갈 수는 있다.
// 자신보다 큰 물고기가 있는 자리는 지나갈 수 없다.
// 자신의 크기와 같은 수의 물고기를 먹으면 상어의 크기가 1 증가한다.
// 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
// 거리가 가까운 물고기가 많다면, 가장 위의 물고기,
// 가장 위의 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int cx, cy; // 상어의 위치
int sz = 2; // 상어의 사이즈
int cnt; // 먹은 물고기 수, 레벨업시 초기화
int board[21][21];
int answer; // 종료까지 걸린 시간
bool eat; // 상어가 물고기를 먹었는지 여부
int dx[4] = { -1, 0, 0, 1 }; // 상,좌,우,하
int dy[4] = { 0, -1, 1, 0 };

void BFS(int x, int y, int curSize, int isVisited[][21])
{
	queue<pair<pair<int, int>, int>> q; // <<x,y>, second>
	q.push({ {x, y}, 0 });
	isVisited[x][y] = true;
	int second = 0; // 처음 물고기를 먹는데 걸린 시간

	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int s = q.front().second;
		q.pop();

		// 물고기를 먹었던 위치와 같은 거리에 물고기가 있는데,
		// 이 위치가 보다 위쪽에 있거나 x값은 똑같으면서 왼쪽에 있으면 이 위치를 저장
		if (board[tx][ty] >= 1 && board[tx][ty] < curSize && second == s)
		{
			if (tx < cx || (tx == cx && ty < cy))
			{
				cx = tx;
				cy = ty;
				//continue;
			}
		}

		for(int i = 0; i < 4; ++i)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			// board 안 좌표이고 방문하지 않은 칸 방문
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !isVisited[nx][ny])
			{
				if (board[nx][ny] <= curSize) // 상어 사이즈보다 작거나 같은 물고기가 있는 칸만 방문가능
				{
					// 상어 사이즈보다 작은 물고기가 있는 경우 먹는다
					if (board[nx][ny] >= 1 && board[nx][ny] < curSize && !eat)
					{
						// 상어위치 저장
						cx = nx;
						cy = ny;
						eat = true;
						second = s + 1;
						// 걸린 시간 더해주기
						answer += s + 1;
					}
					else
					{
						// 그렇지 않다면 지나가기만 한다
						isVisited[nx][ny] = true;
						q.push({ {nx,ny}, s + 1 });
					}
				}
			}
		}
	}
}

int main()
{
	// 입력
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;
			board[i][j] = num;
			if (num == 9)
			{
				cx = i;
				cy = j;
				board[i][j] = 0;
			}
		}
	}

	// 풀이
	int stop = false;
	while (!stop)
	{
		int isVisited[21][21] = { 0, };		
		BFS(cx, cy, sz, isVisited);		
		if (eat) 
		{
			// 먹은 물고기 삭제
			board[cx][cy] = 0;
			// 물고기 먹은 횟수 갱신
			++cnt;
			// 크기 갱신
			if (cnt == sz)
			{
				++sz;
				cnt = 0;
			}
			eat = false;
		}
		else
		{
			// 상어가 물고기를 못 먹었으면 종료
			stop = true;
		}
	}
	cout << answer;

	return 0;
}