#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//    3    0 1 2 3 4 5 6
//  5
//  0
//  1
//  2
//  3

int main()
{
	int N;
	cin >> N;

	int row = N / 5 + 1;
	int column = N / 3 + 1;
	vector<int> dp;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (5 * i + 3 * j == N)
			{
				dp.push_back(i + j);
			}
		}
	}

	if (dp.empty())
	{
		cout << -1;
	}
	else
	{
		cout << *min_element(dp.begin(), dp.end());
	}
	
	return 0;
}