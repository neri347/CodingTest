/// �÷�����
/// https://school.programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<bool>> isVisited;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

int DFS(int x, int y, const vector<vector<int>>& picture)
{
	int count = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && !isVisited[nx][ny]
			&& picture[nx][ny] == picture[x][y])
		{
			isVisited[nx][ny] = true;
			count += DFS(nx, ny, picture);
		}
	}
	return count;
}


// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	M = m;
	N = n;
	isVisited.assign(m, vector<bool>(n, false));
	vector<int> counts;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!isVisited[i][j])
			{
				isVisited[i][j] = true;
				if (picture[i][j] != 0)
				{
					int count = DFS(i, j, picture);
					counts.push_back(count);
				}
			}
		}
	}

	int number_of_area = counts.size();
	int max_size_of_one_area = *max_element(counts.begin(), counts.end());

	return { number_of_area, max_size_of_one_area };
}

int main()
{

	return 0;
}