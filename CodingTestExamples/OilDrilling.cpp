/// ���� ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/250136
/// �ܼ��� DFS�� �������� ���� �ð��ʰ��� ����
/// ���� �����̸� �ѹ����� �����ص� ����� ���� �� �ְ� �����Ͽ���.
/// ���� �����̰� �ִٸ� �� �������� y�� �������� �࿡ ���߰��� ���� ���,
/// ���� �������� ���� �뷮��ŭ ���� �� �ִ�.
/// �׷��� �ѹ� ���� �����̸� �߰��ϸ� �� �������� y�� ���� ���� �� �࿡ ���� �뷮�� �����־���.
/// �̷��� �ϸ� ���� �����̸� �ѹ��� �����ص� �� ���� ���� �뷮�� �˸°� ������ �� �ִ�.
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
	vector<int> oils(M, 0); // �� ���� ������
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!isVisited[i][j])
			{
				isVisited[i][j] = true;
				if (land[i][j] == 1) // ���� ������ �߰�
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