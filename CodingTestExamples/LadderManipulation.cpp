/// ��ٸ� ����
/// https://www.acmicpc.net/problem/15684
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N; // ���μ�
int M; // ���μ�
int H; // ���μ� ��ġ ����
bool ladder[31][11];

bool IsValid()
{
	for (int i = 1; i <= N; i++)
	{
		int pos = i;
		for (int j = 1; j <= H; j++)
		{
			if (ladder[j][pos]) // ���������� �̵�
			{
				pos++;
			}
			else if (ladder[j][pos - 1]) // �������� �̵�
			{
				pos--;
			}
		}
		if (pos != i)
		{
			return false;
		}
	}
	return true;
}

void Backtrack(int count, int maxDepth)
{
	if (maxDepth == count)
	{
		if (IsValid())
		{
			cout << count;
			exit(0);
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			// �� ���� ��ٸ� ������ ��ٸ� ���� �� �ִ�.
			if (ladder[j][i] || ladder[j][i - 1] || ladder[j][i + 1])
			{
				continue;
			}
			ladder[j][i] = true;
			Backtrack(count + 1, maxDepth);
			ladder[j][i] = false;
			while (!ladder[j][i - 1] && !ladder[j][i + 1]) j++; // �� ��ŵ. �ֺ��� ��ٸ� ������ j ��ġ�� ��ٸ� ������ �� ���� ��ٸ� �����Ͱ� ���� ����� ���� �� �ۿ� ����.
		}
	}
}

int main()
{
	cin >> N >> M >> H;
	vector<vector<int>> nomi(M);
	for (int i = 0; i < M; i++)
	{
		int row, column;
		cin >> row >> column;
		ladder[row][column] = true;
	}

	for (int i = 0; i <= 3; i++) // i�� ���� ��ٸ� ����. �ִ� ��ٸ� 3������ ���� �� �ִ�.
	{
		Backtrack(0, i);
	}

	cout << -1;
	return 0;
}