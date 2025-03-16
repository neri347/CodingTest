/// 스타트 택시
/// https://www.acmicpc.net/problem/19238
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Customer
{
	int num;
	int sx;
	int sy;
	int ex;
	int ey;
	int dist;
	bool isArrived;
};

struct Taxi
{
	int x;
	int y;
	int fuel;
};

struct Cmp
{
	bool operator()(const Customer& a, const Customer& b)
	{
		if (a.dist == b.dist)
		{
			if (a.sx == b.sx)
			{
				return a.sy > b.sy;
			}
			return a.sx > b.sx;
		}
		return a.dist > b.dist;
	}
};

int N, M;
Taxi taxi;
int board[20][20];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int DistToCustomer(int sx, int sy, int ex, int ey)
{
	int ret = -1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { sx, sy }, 0 });
	vector<vector<bool>> isVisited(N, vector<bool>(N, false));
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (x == ex && y == ey)
		{
			ret = dist;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[nx][ny] && board[nx][ny] != 1)
			{
				isVisited[nx][ny] = true;
				q.push({ {nx, ny}, dist + 1 });
			}
		}
	}

	return ret;
}

int main()
{
	int F;
	cin >> N >> M >> F;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int v;
			cin >> v;
			board[i][j] = v;
		}
	}

	int sx, sy;
	cin >> sx >> sy;
	taxi.x = sx - 1;
	taxi.y = sy - 1;
	taxi.fuel = F;

	vector<Customer> customers;
	for (int i = 0; i < M; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		customers.push_back({ i, sx - 1, sy - 1, ex - 1, ey - 1, -1, false });
	}

	for (int i = 0; i < M; i++)
	{
		// 가장 가까운 손님 위치로 가기
		priority_queue<Customer, vector<Customer>, Cmp> pq;
		for (auto& c : customers)
		{
			if (c.isArrived)
				continue;
			c.dist = DistToCustomer(taxi.x, taxi.y, c.sx, c.sy);
			if (c.dist == -1)
			{
				cout << -1;
				return 0;
			}
			pq.push(c);
		}

		Customer nearestCustomer = pq.top();
		taxi.x = nearestCustomer.sx;
		taxi.y = nearestCustomer.sy;
		taxi.fuel -= nearestCustomer.dist;

		// 손님 태우고 목적지까지 가기
		int idx = nearestCustomer.num; // 손님번호
		customers[idx].isArrived = true;
		int endX = customers[idx].ex;
		int endY = customers[idx].ey;

		bool arriveFlag = false;
		queue<pair<pair<int, int>, int>> q;
		q.push({ { taxi.x, taxi.y }, 0 });
		vector<vector<bool>> isVisited(N, vector<bool>(N, false));
		while (!q.empty())
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int move = q.front().second;
			q.pop();

			if (x == endX && y == endY)
			{
				taxi.x = x;
				taxi.y = y;
				taxi.fuel += move; // 연료 채우기
				arriveFlag = true;
				break;
			}

			if (taxi.fuel - move <= 0)
			{
				continue;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[nx][ny] && board[nx][ny] != 1)
				{
					isVisited[nx][ny] = true;
					q.push({ {nx, ny}, move + 1 });
				}
			}
		}

		if (!arriveFlag)
		{
			cout << -1;
			return 0;
		}
	}

	cout << taxi.fuel;
	return 0;
}