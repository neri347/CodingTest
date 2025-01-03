/// p.764 문제81_부분 배낭 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const vector<double>& v1, const vector<double>& v2)
{
	return v1[2] > v2[2];
}

double solution(vector<vector<double>> items, double weight_limit)
{
	double maxValue = 0.0;
	double currentWeight = 0.0;
	for (int i = 0; i < items.size(); ++i)
	{
		items[i].push_back(items[i][1] / items[i][0]);
	}
	sort(items.begin(), items.end(), Compare);
	for (int i = 0; i < items.size(); ++i)
	{
		double remain = weight_limit - currentWeight;
		if (remain >= items[i][0])
		{
			maxValue += items[i][1];
			currentWeight += items[i][0];
		}
		else // 남은 무게 쪼개서 넣고 종료
		{
			// items[i][2] = 1 당 가치
			maxValue += items[i][2] * remain;
			break;
		}
	}

	return maxValue;
}

int main()
{
	vector<vector<double>> items = { {10,19}, {7,10}, {6,10} };
	double weight_limit = 15;
	cout << solution(items, weight_limit);
	return 0;
}