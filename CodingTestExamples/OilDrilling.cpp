/// 석유 시추
/// https://school.programmers.co.kr/learn/courses/30/lessons/250136
/// 단순히 DFS만 적용했을 때는 시간초과가 나서
/// 석유 웅덩이를 한번씩만 조사해도 결과가 나올 수 있게 변경하였다.
/// 석유 웅덩이가 있다면 그 웅덩이의 y값 범위내의 행에 시추관이 들어올 경우,
/// 석유 웅덩이의 오일 용량만큼 뽑을 수 있다.
/// 그래서 한번 석유 웅덩이를 발견하면 그 웅덩이의 y값 범위 내의 각 행에 석유 용량을 더해주었다.
/// 이렇게 하면 석유 웅덩이를 한번만 조사해도 각 행의 석유 용량을 알맞게 저장할 수 있다.
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
vector<vector<bool>> isVisited;

void DFS(int row, int column, int& count, set<int>& rangeY, vector<vector<int>>& land)
{
	rangeY.insert(column);

	for (int i = 0; i < 4; i++)
	{
		int nr = row + dx[i];
		int nc = column + dy[i];
		if (nr >= 0 && nr < N && nc >= 0 && nc < M && !isVisited[nr][nc] && land[nr][nc] == 1)
		{
			isVisited[nr][nc] = true;
			count++;
			DFS(nr, nc, count, rangeY, land);
		}
	}
}

int solution(vector<vector<int>> land) {
	N = land.size();
	M = land[0].size();
	isVisited.assign(N, vector<bool>(M, false));
	vector<int> oils(M, 0); // 각 행의 석유량
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!isVisited[i][j])
			{
				isVisited[i][j] = true;
				if (land[i][j] == 1) // 석유 웅덩이 발견
				{
					set<int> rangeY;
					int count = 1;
					DFS(i, j, count, rangeY, land);
					for (auto& e : rangeY)
					{
						oils[e] += count;
					}
				}
			}
		}
	}
	return *max_element(oils.begin(), oils.end());
}

int main()
{

	return 0;
}