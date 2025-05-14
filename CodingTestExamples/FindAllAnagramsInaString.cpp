#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> answer;
		unordered_map<char, int> pm;
		unordered_map<char, int> sm;
		for (auto& ch : p)
		{
			pm[ch]++;
		}

		int left = 0;
		int right = 0;
		while (right < s.size())
		{
			sm[s[right]]++;

			if (right - left + 1 < p.size())
			{
				right++;
			}
			else
			{
				if (sm == pm)
				{
					answer.push_back(left);
				}
				sm[s[left]]--;
				if (sm[s[left]] == 0)
				{
					sm.erase(s[left]);
				}
				left++;
				right++;
			}
		}
		return answer;
	}
};

int main()
{
	Solution solution;
	solution.findAnagrams("cbaebabacd", "abc");
	return 0;
}