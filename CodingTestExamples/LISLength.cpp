/// p.706 ����71_LIS ���� ����ϱ�
/// LIS = ���� ���� �κ� ����
/// �κ� ���� �� ���������̰� ���̰� ���� �� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N�� ���� ��ġ, �����ε����� 1
// dp[1] = 1
// dp[N] = max(dp[N], dp[K] + 1) (1 <= K < N, arr[K] < arr[N])

int solution(vector<int> nums)
{
	vector<int> dp(nums.size(), 0);
	dp[0] = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
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