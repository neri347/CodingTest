/// 1로 만들기
/// https://www.acmicpc.net/problem/1463
/// 재귀함수보다 동적 프로그래밍이 훨씬 빠른 것을 알 수 있는 문제.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> nums;

int MakeToOne(int n)
{
	if (n == 1)
	{
		return nums[1];
	}

	if (nums[n] != 0)
	{
		return nums[n];
	}

	int divideThree = INT_MAX;
	int divideTwo = INT_MAX;
	int subOne = INT_MAX;

	if (n % 3 == 0)
	{
		divideThree = MakeToOne(n / 3) + 1;
	}
	if (n % 2 == 0)
	{
		divideTwo = MakeToOne(n / 2) + 1;
	}
		
	subOne = MakeToOne(n - 1) + 1;	

	nums[n] = min({ divideThree, divideTwo, subOne });
	return nums[n];
}

int main()
{
	int n;
	cin >> n;
	nums.assign(n + 1, 0);
	cout << MakeToOne(n);
	return 0;
}