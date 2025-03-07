/// �ֻ��� ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/258709
/// A�� n�� �߿� n/2�� �ֻ����� ���� ���
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> diceInfo;

void RollDice(int index, int curSum, const vector<int>& dice, vector<int>& sum)
{
	if (index == dice.size())
	{
		sum.push_back(curSum);
		return;
	}

	int d = dice[index];
	for (int i = 0; i < diceInfo[d].size(); i++)
	{
		curSum += diceInfo[d][i];
		RollDice(index + 1, curSum, dice, sum);
		curSum -= diceInfo[d][i];
	}
}

vector<int> solution(vector<vector<int>> dice) {
	vector<int> answer;
	int victory = 0; // �ִ� �¸�Ƚ��
	diceInfo = dice;
	int n = dice.size();
	vector<int> combi;
	for (int i = 0; i < n / 2; i++)
	{
		combi.push_back(0);
	}
	for (int i = 0; i < n / 2; i++)
	{
		combi.push_back(1);
	}

	do 
	{
		// �ֻ��� ����
		vector<int> diceA;
		vector<int> diceB;
		for (int i = 0; i < combi.size(); i++)
		{
			if (combi[i] == 1)
			{
				diceA.push_back(i);
			}
			else
			{
				diceB.push_back(i);
			}
		}

		// �ֻ��� ������
		vector<int> sumA;
		vector<int> sumB;
		RollDice(0, 0, diceA, sumA);
		RollDice(0, 0, diceB, sumB);

		// �� �� �� ���� ����
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
			answer = diceA;
		}

	} while (next_permutation(combi.begin(), combi.end()));

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