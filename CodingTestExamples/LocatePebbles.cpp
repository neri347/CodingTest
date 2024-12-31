/// p.709 문제72_조약돌 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//////////////////////	|
//	//	//	//	//	//	|
//////////////////////	|
//	//	//	//	//	//	|
//////////////////////	|
//	//	//	//	//	//	|
//////////////////////	V
//w1  w2  w3  w4  w5 = total

int solution(vector<vector<int>> arr)
{
	int n = arr[0].size();
	// 한 열당 4가지 경우 수
	// 0 = 위, 1 = 가운데, 2 = 아래, 3 = 위아래
	vector<vector<int>> dp(4, vector<int>(n, 0));
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[2][0] = arr[2][0];
	dp[3][0] = arr[0][0] + arr[2][0];

	for (int i = 1; i < n; ++i)
	{
		// 현재 패턴 0번이라면(위), 이전 패턴은 1번 혹은 2번
		dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[2][i - 1]);
		// 현재 패턴 1번이라면(가운데), 이전 패턴은 0번 혹은 2번 혹은 3번
		dp[1][i] = arr[1][i] + max({ dp[0][i - 1], dp[2][i - 1], dp[3][i - 1] });
		// 현재 패턴 2번이라면(아래), 이전 패턴은 0번 혹은 1번
		dp[2][i] = arr[2][i] + max(dp[0][i - 1], dp[1][i - 1]);
		// 현재 패턴 3번이라면(위아래), 이전 패턴은 1번
		dp[3][i] = arr[0][i] + arr[2][i] + dp[1][i - 1];
	}
	// 마지막 열 중에 최대값 반환
	return max({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1], dp[3][n - 1] });
}

int main()
{
	vector<vector<int>> arr = { {1,3,3,2}, {2,1,4,1}, {1,5,2,3} };
	cout << solution(arr);
	return 0;
}