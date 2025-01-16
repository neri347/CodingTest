/// �ֻ��� ������
/// https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int board[20][20];
int dx[4] = { 0, 0, -1, 1 }; // �����ϳ�
int dy[4] = { 1, -1, 0, 0 };

int main()
{
	// �Է�
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
	// Ǯ��
	vector<int> dice(6, 0); //0 : ����, 1:�޸�, 2:�����ʸ�, 3:���ʸ�, 4:�ո�, 5:�ظ�
	for (int i = 0; i < orderCnt; ++i)
	{
		int order = orders[i];
		int nx = cx + dx[order - 1];
		int ny = cy + dy[order - 1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			// �ֻ��� ������
			if (order == 1) // ��
			{
				int top = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = top;
			}
			else if (order == 2) // ��
			{
				int top = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = top;
			}
			else if (order == 3) // ��
			{
				int top = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = top;
			}
			else // ��
			{
				int top = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = top;
			}

			// �̵��� ĭ�� �����ִ� ���� 0�̸�, �ֻ��� �ظ� ���� ����
			if (board[nx][ny] == 0)
			{
				board[nx][ny] = dice[5];
			}
			else	// 0�� �ƴϸ� ĭ�� �����ִ� ���� �ֻ��� �ظ� ����. ĭ�� 0�� ��.
			{
				dice[5] = board[nx][ny];
				board[nx][ny] = 0;
			}
			answer.push_back(dice[0]);
			cx = nx;
			cy = ny;
		}
	}

	// ���
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}