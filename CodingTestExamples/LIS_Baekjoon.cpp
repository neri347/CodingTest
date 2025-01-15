/// 가장 긴 증가하는 부분 수열
/// https://www.acmicpc.net/problem/11053
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(int start, int end, int element, const vector<int>& vec)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (vec[mid] < element)
		{
			start = mid + 1;			
		}
		else
		{
			end = mid;
		}
	}
	return end;
}

int main()
{
	// 입력
	int N;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}
	
	// 풀이
	vector<int> vec;
	vec.push_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i)
	{
		// 벡터의 마지막 원소가 현재 값보다 작다면 그냥 벡터 뒤에 삽입한다.
		if (vec.back() < nums[i])
		{
			vec.push_back(nums[i]);
		}
		else
		{
			int pos = BinarySearch(0, vec.size() - 1, nums[i], vec);
			vec[pos] = nums[i];
		}
	}
	cout << vec.size();

	return 0;
}