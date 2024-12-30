/// p.651 문제62_배열 회전하기
/// 2차원 배열 arr을 시계 방향으로 90도 * n번 회전하는 solution()을 작성하세요.
#include <iostream>
#include <vector>
using namespace std;

// A[y,x] => A[x, N-1-y]
// A[0,0] => A[2,0]
// A[2,0] => A[0,0]
vector<vector<int>> Rotate_90(const vector<vector<int>>& origin)
{
	vector<vector<int>> rotated = origin;
	int N = origin.size();
	for (int i = 0; i < origin.size(); ++i)
	{
		for (int j = 0; j < origin[i].size(); ++j)
		{
			rotated[i][j] = origin[N - 1 - j][i];
		}
	}
	return rotated;
}

vector<vector<int>> solution(vector<vector<int>> arr, int n)
{
	vector<vector<int>> ret = arr;
	for (int i = 0; i < n; ++i)
	{
		ret = Rotate_90(ret);
	}
	return ret;
}

int main()
{
	vector<vector<int>> arr = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	int n = 1;
	for (const auto& v : solution(arr, n))
	{
		for (const auto& n : v)
		{
			cout << n << " ";
		}
		cout << "\n";
	}
	return 0;
}