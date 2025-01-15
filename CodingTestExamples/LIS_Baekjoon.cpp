/// ���� �� �����ϴ� �κ� ����
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
	// �Է�
	int N;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}
	
	// Ǯ��
	vector<int> vec;
	vec.push_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i)
	{
		// ������ ������ ���Ұ� ���� ������ �۴ٸ� �׳� ���� �ڿ� �����Ѵ�.
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