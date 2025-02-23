/// 감시
/// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// cctv 설치된 장소도 감시되는 것으로 친다.

int N, M;
int board[8][8];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 }; // 동 서 남 북
int answer = INT_MAX;
vector<pair<pair<int, int>, int>> cctvPos; // x, y, type
vector<pair<int, int>> cctv_three = { {0, 3}, {2, 0}, {1, 2}, {3, 1} }; // 동북, 남동, 서남, 북서

void CheckBlindSpot(int index, vector<vector<bool>>& isWatched)
{
	if (index == cctvPos.size())
	{
		// 사각지대 개수 세기
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!isWatched[i][j])
				{
					count++;
				}
			}
		}
		answer = min(answer, count);
		return;
	}

	int x = cctvPos[index].first.first;
	int y = cctvPos[index].first.second;
	int type = cctvPos[index].second;
	if (type == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			vector<vector<bool>> temp = isWatched;
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6)
			{
				temp[nx][ny] = true;
				nx += dx[i];
				ny += dy[i];
			}
			CheckBlindSpot(index + 1, temp);
		}		
	}
	else if (type == 2)
	{
		for (int i = 0; i < 4; i+=2)
		{
			vector<vector<bool>> temp = isWatched;
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6)
			{
				temp[nx][ny] = true;
				nx += dx[i];
				ny += dy[i];
			}
			nx = x - dx[i];
			ny = y - dy[i];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6)
			{
				temp[nx][ny] = true;
				nx -= dx[i];
				ny -= dy[i];
			}
			CheckBlindSpot(index + 1, temp);
		}
	}
	else if (type == 3)
	{		
		for (int i = 0; i < 4; i++) 
		{
			vector<vector<bool>> temp = isWatched;
			pair<int, int> dir = cctv_three[i];
			int nx = x + dx[dir.first];
			int ny = y + dy[dir.first];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6)
			{
				temp[nx][ny] = true;
				nx += dx[dir.first];
				ny += dy[dir.first];
			}

			nx = x + dx[dir.second];
			ny = y + dy[dir.second];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6)
			{
				temp[nx][ny] = true;
				nx += dx[dir.second];
				ny += dy[dir.second];
			}
			CheckBlindSpot(index + 1, temp);
		}
	}
	else if (type == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			vector<vector<bool>> temp = isWatched;
			for (int j = 0; j < 4; j++)
			{
				if (i == j)
				{
					continue;
				}
				int nx = x + dx[j];
				int ny = y + dy[j];
				while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6)
				{
					temp[nx][ny] = true;
					nx += dx[j];
					ny += dy[j];
				}
			}
			CheckBlindSpot(index + 1, temp);
		}
	}
	else
	{
		vector<vector<bool>> temp = isWatched;
		for (int i = 0; i < 4; i++)
		{			
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6)
			{
				temp[nx][ny] = true;
				nx += dx[i];
				ny += dy[i];
			}
		}
		CheckBlindSpot(index + 1, temp);
	}
}

int main()
{
	cin >> N >> M;
	vector<vector<bool>> isWatched(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int value;
			cin >> value;
			board[i][j] = value;
			if (value >= 1)
			{
				isWatched[i][j] = true;
			}
			if (value >= 1 && value <= 5)
			{				
				cctvPos.push_back({ { i, j }, value });
			}
		}
	}

	CheckBlindSpot(0, isWatched);
	cout << answer;
	return 0;
}