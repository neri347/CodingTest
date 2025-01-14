/// �Ʊ� ���
/// https://www.acmicpc.net/problem/16236

// ����� ó�� ũ��� 2�̰�, 1�ʿ� �� ĭ�� �̵�
// �ڽź��� ���� ����⸸ ���� �� �ִ�.
// �ڽŰ� ���� ũ���� ����Ⱑ �ִ� �ڸ��� ������ ���� �ִ�.
// �ڽź��� ū ����Ⱑ �ִ� �ڸ��� ������ �� ����.
// �ڽ��� ũ��� ���� ���� ����⸦ ������ ����� ũ�Ⱑ 1 �����Ѵ�.
// ���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
// �Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �����,
// ���� ���� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int cx, cy; // ����� ��ġ
int sz = 2; // ����� ������
int cnt; // ���� ����� ��, �������� �ʱ�ȭ
int board[21][21];
int answer; // ������� �ɸ� �ð�
bool eat; // �� ����⸦ �Ծ����� ����
int dx[4] = { -1, 0, 0, 1 }; // ��,��,��,��
int dy[4] = { 0, -1, 1, 0 };

void BFS(int x, int y, int curSize, int isVisited[][21])
{
	queue<pair<pair<int, int>, int>> q; // <<x,y>, second>
	q.push({ {x, y}, 0 });
	isVisited[x][y] = true;
	int second = 0; // ó�� ����⸦ �Դµ� �ɸ� �ð�

	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int s = q.front().second;
		q.pop();

		// ����⸦ �Ծ��� ��ġ�� ���� �Ÿ��� ����Ⱑ �ִµ�,
		// �� ��ġ�� ���� ���ʿ� �ְų� x���� �Ȱ����鼭 ���ʿ� ������ �� ��ġ�� ����
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
			// board �� ��ǥ�̰� �湮���� ���� ĭ �湮
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !isVisited[nx][ny])
			{
				if (board[nx][ny] <= curSize) // ��� ������� �۰ų� ���� ����Ⱑ �ִ� ĭ�� �湮����
				{
					// ��� ������� ���� ����Ⱑ �ִ� ��� �Դ´�
					if (board[nx][ny] >= 1 && board[nx][ny] < curSize && !eat)
					{
						// �����ġ ����
						cx = nx;
						cy = ny;
						eat = true;
						second = s + 1;
						// �ɸ� �ð� �����ֱ�
						answer += s + 1;
					}
					else
					{
						// �׷��� �ʴٸ� �������⸸ �Ѵ�
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
	// �Է�
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

	// Ǯ��
	int stop = false;
	while (!stop)
	{
		int isVisited[21][21] = { 0, };		
		BFS(cx, cy, sz, isVisited);		
		if (eat) 
		{
			// ���� ����� ����
			board[cx][cy] = 0;
			// ����� ���� Ƚ�� ����
			++cnt;
			// ũ�� ����
			if (cnt == sz)
			{
				++sz;
				cnt = 0;
			}
			eat = false;
		}
		else
		{
			// �� ����⸦ �� �Ծ����� ����
			stop = true;
		}
	}
	cout << answer;

	return 0;
}