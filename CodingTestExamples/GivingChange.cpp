/// p.762 문제80_거스름돈 주기
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int amount)
{
	int moneys[4] = { 100, 50, 10, 1 };
	int moneyIndex = 0;
	vector<int> ret;
	while (amount > 0)
	{
		if (amount >= moneys[moneyIndex])
		{
			ret.push_back(moneys[moneyIndex]);
			amount -= moneys[moneyIndex];
		}
		else
		{
			moneyIndex++;
		}
	}

	return ret;
}

int main()
{
	int amount = 350;
	for (const auto& n : solution(amount))
	{
		cout << n << " ";
	}
	return 0;
}