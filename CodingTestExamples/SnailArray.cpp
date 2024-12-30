/// p.656 문제64_달팽이 수열 만들기
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> solution(int n)
{
	// n = 4
	// Step1		y  x
	// 1. x + 1 3번 [0][0~2]
	// 2. y + 1 3번 [0~2][3]
	// 3. x - 1 3번 [3][3~1]
	// 4. y - 1 3번 [3~1][0]
	//-----
	// Step2
	// 1. x + 1 2번
	// 2. y + 1 2번
	// 3. x - 1 2번
	// 4. y - 1 2번
	vector<vector<int>> ret(n, vector<int>(n, 0));
	int len = n - 1;
	int dir = 0;
	int num = 1;
	int startRow = 0;
	int endRow = n - 1;
	int startCol = 0;
	int endCol = n - 1;
	// startRow > endRow || startCol > endCol 되는 순간 끝남
	while (startRow <= endRow && startCol <= endCol)
	{
		// 왼쪽위부터 오른쪽위까지
		for (int i = startCol; i <= endCol; ++i)
		{
			ret[startRow][i] = num++;
		}
		++startRow;

		// 오른쪽위부터 오른쪽 아래까지
		for (int i = startRow; i <= endRow; ++i)
		{
			ret[i][endCol] = num++;
		}
		--endCol;

		// 오른쪽 아래부터 왼쪽 아래까지
		if (startRow <= endRow)
		{
			for (int i = endCol; i >= startCol; --i)
			{
				ret[endRow][i] = num++;
			}
			--endRow;
		}

		// 왼쪽 아래부터 왼쪽 위 전까지
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