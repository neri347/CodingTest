/// ¡¡¥Ÿ
/// https://www.acmicpc.net/problem/1253
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums;
	
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	int answer = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i)
	{
		int goal = nums[i];
		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			int sum = nums[left] + nums[right];
			if (sum > goal)
			{
				right--;
			}
			else if (sum < goal)
			{
				++left;
			}
			else // sum == goal
			{
				if (left != i && right != i)
				{
					++answer;
					break;
				}
				else if (left == i)
				{
					++left;
				}
				else
				{
					--right;
				}
			}
		}
	}
	cout << answer;

	return 0;
}