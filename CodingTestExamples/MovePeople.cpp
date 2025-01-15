/// 인구 이동
/// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, R;
int lands[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y, bool isVisited[][50], vector<pair<int, int>>& linked)
{
	isVisited[x][y] = true;
	linked.push_back({ x, y });

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !isVisited[nx][ny])
		{
			int diff = abs(lands[x][y] - lands[nx][ny]);
			if (diff >= L && diff <= R)
			{
				DFS(nx, ny, isVisited, linked);
			}
		}
	}
}

int main()
{
	// 입력
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int n;
			cin >> n;
			lands[i][j] = n;
		}
	}

	// 풀이
	int answer = 0;
	while (true)
	{
		vector<vector<pair<int, int>>> associations;
		bool isVisited[50][50] = { false, };
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				vector<pair<int, int>> linkedCountries;
				if (!isVisited[i][j])
				{
					DFS(i, j, isVisited, linkedCountries);
				}
				if (linkedCountries.size() > 1)
				{
					associations.push_back(linkedCountries);
				}
			}
		}
		if (associations.size() == 0)
		{
			break;
		}
		else
		{
			// 연합끼리 인구이동
			for (auto& asso : associations)
			{
				int sum = 0;
				// 한 연합 내 각 나라들의 인구 수 모두 더함
				for (auto& country : asso)
				{
					sum += lands[country.first][country.second];
				}
				int newValue = sum / asso.size();
				// 인구분배
				for (auto& country : asso)
				{
					lands[country.first][country.second] = newValue;
				}
			}
			++answer;
		}
	}
	cout << answer;
	return 0;
}