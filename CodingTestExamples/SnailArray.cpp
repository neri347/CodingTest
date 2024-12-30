/// p.656 ����64_������ ���� �����
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> solution(int n)
{
	// n = 4
	// Step1		y  x
	// 1. x + 1 3�� [0][0~2]
	// 2. y + 1 3�� [0~2][3]
	// 3. x - 1 3�� [3][3~1]
	// 4. y - 1 3�� [3~1][0]
	//-----
	// Step2
	// 1. x + 1 2��
	// 2. y + 1 2��
	// 3. x - 1 2��
	// 4. y - 1 2��
	vector<vector<int>> ret(n, vector<int>(n, 0));
	int len = n - 1;
	int dir = 0;
	int num = 1;
	int startRow = 0;
	int endRow = n - 1;
	int startCol = 0;
	int endCol = n - 1;
	// startRow > endRow || startCol > endCol �Ǵ� ���� ����
	while (startRow <= endRow && startCol <= endCol)
	{
		// ���������� ������������
		for (int i = startCol; i <= endCol; ++i)
		{
			ret[startRow][i] = num++;
		}
		++startRow;

		// ������������ ������ �Ʒ�����
		for (int i = startRow; i <= endRow; ++i)
		{
			ret[i][endCol] = num++;
		}
		--endCol;

		// ������ �Ʒ����� ���� �Ʒ�����
		if (startRow <= endRow)
		{
			for (int i = endCol; i >= startCol; --i)
			{
				ret[endRow][i] = num++;
			}
			--endRow;
		}

		// ���� �Ʒ����� ���� �� ������
		if (startCol <= endCol)
		{
			for (int i = endRow; i >= startRow; --i)
			{
				ret[i][startCol] = num++;
			}
			++startCol;
		}
	}
	return ret;
}

int main()
{
	for (const auto& v : solution(10))
	{
		for (const auto& n : v)
		{
			cout << n << "\t";
		}
		cout << "\n";
	}
	return 0;
}