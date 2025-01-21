/// ¿¬»êÀÚ ³¢¿ö³Ö±â
/// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 = +, 2 = -, 3 = *, 4 = /

int main()
{
	// ÀÔ·Â
	int N;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}
	vector<int> operators;
	int plus, minus, multiple, divide;
	cin >> plus >> minus >> multiple >> divide;
	for (int i = 0; i < plus; ++i)
	{
		operators.push_back(1);
	}
	for (int i = 0; i < minus; ++i)
	{
		operators.push_back(2);
	}
	for (int i = 0; i < multiple; ++i)
	{
		operators.push_back(3);
	}
	for (int i = 0; i < divide; ++i)
	{
		operators.push_back(4);
	}

	// Ç®ÀÌ
	int maxVal = -1000000001;
	int minVal = 1000000001;
	do
	{
		int ret = nums[0];
		for (int i = 1; i < N; ++i)
		{
			if (operators[i - 1] == 1) // µ¡¼À
			{
				ret += nums[i];
			}
			else if (operators[i - 1] == 2) // »¬¼À
			{
				ret -= nums[i];
			}
			else if (operators[i - 1] == 3) // °ö¼À
			{
				ret *= nums[i];
			}
			else // ³ª´°¼À
			{
				if (nums[i] < 0)
				{
					int d = ret / (-nums[i]);
					ret = -d;
				}
				else
				{
					ret /= nums[i];
				}
			}
		}
		maxVal = max(maxVal, ret);
		minVal = min(minVal, ret);
	} while (next_permutation(operators.begin(), operators.end()));

	cout << maxVal << "\n";
	cout << minVal << "\n";
	return 0;
}