/// �ֻ��� ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/258709
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Dice(int val, const vector<int>& combi)
{
	vector<int> ret;
	for (int i = 0; i < combi.size(); i++)
	{
		if (combi[i] == val)
		{
			ret.push_back(i);
		}
	}
	return ret;
}

void CalSum(int index, int maxSum, const vector<int>& combi, const vector<vector<int>>& dice, vector<int>& sum)
{
	if (index == combi.size())
	{
		sum.push_back(maxSum);
		return;
	}

	int d = combi[index];
	for (int i = 0; i < dice[d].size(); i++)
	{
		maxSum += dice[d][i];
		CalSum(index + 1, maxSum, combi, dice, sum);
		maxSum -= dice[d][i];
	}
}

vector<int> solution(vector<vector<int>> dice) {
	vector<int> answer;
	int victory = 0;
	int n = dice.size();
	vector<int> combi(n, 0);
	for (int i = 0; i < n / 2; i++)
	{
		combi[i] = 1;
	}
	for (int i = n / 2; i < n; i++)
	{
		combi[i] = 2;
	}

	do
	{
		// �ֻ��� ����
		vector<int> diceCombiA = Dice(1, combi);
		vector<int> diceCombiB = Dice(2, combi);
		// �ֻ��� ���տ� ���� ��
		vector<int> sumA;
		vector<int> sumB;
		CalSum(0, 0, diceCombiA, dice, sumA);
		CalSum(0, 0, diceCombiB, dice, sumB);
		// �� �� �� ���� ���� ���� ����
		int v = 0;
		for (int i = 0; i < sumA.size(); i++)
		{
			for (int j = 0; j < sumB.size(); j++)
			{
				if (sumA[i] > sumB[j])
				{
					++v;
				}
			}
		}
		if (v > victory)
		{
			victory = v;
			answer = diceCombiA;
		}

	} while (next_permutation(combi.begin(), combi.end()));

	// �ֻ��� ��ȣ�� 1������ �����̹Ƿ� +1
	for (int i = 0; i < answer.size(); i++)
	{
		++answer[i];
	}

	return answer;
}

int main()
{

	return 0;
}