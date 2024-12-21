/// ÁöÆó Á¢±â
/// https://school.programmers.co.kr/learn/courses/30/lessons/340199
#include <iostream>
#include <vector>
using namespace std;

bool IsBillCanFold(const vector<int>& wallet, const vector<int>& bill)
{
	int walletSmallest = min(wallet[0], wallet[1]);
	int billSmallest = min(bill[0], bill[1]);
	if (walletSmallest < billSmallest)
	{
		return true;
	}
	int walletBiggest = max(wallet[0], wallet[1]);
	int billBiggest = max(bill[0], bill[1]);
	if (walletBiggest < billBiggest)
	{
		return true;
	}

	return false;
}

int solution(vector<int> wallet, vector<int> bill) {
	int answer = 0;
	while (IsBillCanFold(wallet, bill))
	{
		if (bill[0] > bill[1])
		{
			bill[0] /= 2;
		}
		else
		{
			bill[1] /= 2;
		}
		++answer;
	}
	return answer;
}

int main()
{

	return 0;
}