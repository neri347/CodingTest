#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;
	vector<vector<int>> giveCounts;
	vector<int> giftScores(friends.size(), 0);
	unordered_map<string, int> indexMap;
	vector<int> nextMonthGifts(friends.size(), 0);
	// �ε��� ����
	for (int i = 0; i < friends.size(); i++)
	{
		indexMap.insert({ friends[i], i });
	}

	// ǥ �ʱ�ȭ
	for (int i = 0; i < friends.size(); i++)
	{
		vector<int> g;
		for (int j = 0; j < friends.size(); j++)
		{
			g.push_back(0);
		}
		giveCounts.push_back(g);
	}

	for (const auto& str : gifts)
	{
		stringstream ss(str);
		string from, to;
		ss >> from >> to;

		giveCounts[indexMap[from]][indexMap[to]]++;
		giftScores[indexMap[from]]++;
		giftScores[indexMap[to]]--;
	}

	for (int i = 0; i < giveCounts.size(); ++i)
	{
		for (int j = 0; j < giveCounts[i].size(); ++j)
		{
			if (i != j)
			{
				if (giveCounts[i][j] > giveCounts[j][i]) // ���溸�� ���� �־��ٸ�
				{
					// ���� �޿� ���� ���� ���� +1
					++nextMonthGifts[i];
				}
				else if (giveCounts[i][j] == giveCounts[j][i]) // �ְ���� �ʾҰų� �ְ���� ���� ���ٸ�
				{
					// ���� �������� �� ���ٸ� ������ ���� +1
					if (giftScores[i] > giftScores[j])
					{
						++nextMonthGifts[i];
					}
				}
			}
		}
	}

	for (int i = 0; i < nextMonthGifts.size(); ++i)
	{
		answer = max(answer, nextMonthGifts[i]);
	}

	return answer;
}
int main()
{
	
	return 0;
}