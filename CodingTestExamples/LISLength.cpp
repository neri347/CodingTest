/// p.706 문제71_LIS 길이 계산하기
/// LIS = 최장 증가 부분 수열
/// 부분 수열 중 오름차순이고 길이가 가장 긴 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N은 현재 위치, 시작인덱스는 1
// dp[N] = max(dp[K]) + 1 (1 <= K < N, arr[K] < arr[N])
// dp[1] = 1

int solution(vector<int> nums)
{
	vector<int> dp(nums.size(), 0);
	dp[0] = 1;
	for (int N = 1; N < nums.size(); ++N)
	{
		dp[N] = 1;
		for (int K = 0; K < N; ++K)
		{
			if (nums[N] > nums[K])
			{
				dp[N] = max(dp[N], dp[K] + 1);
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main()
{
	//vector<int> nums = { 1,4,2,3,1,5,7,3 };
	vector<int> nums = { 50,60,10,20,30,40 };
	cout << solution(nums);
	return 0;
}