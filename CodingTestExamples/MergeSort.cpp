/// p.616 문제55_정렬이 완료된 두 배열 합치기
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr1, vector<int> arr2)
{
	int idx1 = 0;
	int idx2 = 0;
	vector<int> ret;
	while (idx1 < arr1.size() && idx2 < arr2.size())
	{
		if (arr1[idx1] > arr2[idx2])
		{
			ret.push_back(arr2[idx2++]);
		}
		else
		{
			ret.push_back(arr1[idx1++]);
		}
	}

	while (idx1 < arr1.size())
	{
		ret.push_back(arr1[idx1++]);
	}

	while (idx2 < arr2.size())
	{
		ret.push_back(arr2[idx2++]);
	}

	return ret;
}

int main()
{
	vector<int> arr1 = { 1,3,5 };
	vector<int> arr2 = { 2,4,6 };

	for (const auto& e : solution(arr1, arr2))
	{
		cout << e << " ";
	}

	return 0;
}