/// 메뉴 리뉴얼
/// https://school.programmers.co.kr/learn/courses/30/lessons/72411
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	unordered_map<string, int> candidates;
	for (int i = 0; i < orders.size(); ++i)
	{
		string s = orders[i];
		sort(s.begin(), s.end());
		for (auto& count : course)
		{
			// 코스요리 후보 개수보다 주문된 개수가 적으면 코스요리 후보에 들어가지 않는다.
			if (s.size() < count)
			{
				break;
			}
			vector<int> temp;
			for (int j = 0; j < s.size() - count; ++j)
			{
				temp.push_back(0);
			}
			for (int k = 0; k < count; ++k)
			{
				temp.push_back(1);
			}

			do
			{
				string candidate = "";
				for (int c = 0; c < s.size(); ++c)
				{
					if (temp[c] == 1)
					{
						candidate += s[c];
					}
				}
				candidates[candidate]++;
			} while (next_permutation(temp.begin(), temp.end()));
		}
	}

	for (auto& count : course)
	{
		int maxCount = 0;
		for (const auto& kv : candidates)
		{
			if (kv.first.size() == count && kv.second >= 2)
			{
				maxCount = max(maxCount, kv.second);
			}
		}

		for (const auto& kv : candidates)
		{
			if (kv.first.size() == count && kv.second == maxCount)
			{
				answer.push_back(kv.first);
			}
		}
	}
	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2,3,4 };
	solution(orders, course);
	return 0;
}