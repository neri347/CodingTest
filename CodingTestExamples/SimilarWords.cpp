/// 비슷한 단어
/// https://www.acmicpc.net/problem/2607
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool IsValid(const unordered_map<char, int>& origin, unordered_map<char, int> m)
{
	for (auto& p : origin)
	{
		if (m.count(p.first))
		{
			m[p.first] -= p.second;
			if (m[p.first] <= 0)
			{
				m.erase(p.first);
			}
		}
	}

	if (m.size() < 2)
	{
		if (!m.empty())
		{
			if (m.begin()->second < 2)
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int N;
	cin >> N;
	string firstStr;
	cin >> firstStr;	

	int answer = 0;
	for (int i = 0; i < N - 1; i++)
	{
		string str;
		cin >> str;
		unordered_map<char, int> wordMap;
		for (auto& ch : str)
		{
			wordMap[ch]++;
		}

		unordered_map<char, int> firstWordMap;
		for (auto& ch : firstStr)
		{
			firstWordMap[ch]++;
		}

		// temp에서 m의 문자들을 다 빼고 남은 문자가 2가지 이상이거나
		// 한 가지 문자만 남았더라도 2개 이상 남았다면 비슷한 단어가 아니다.
		// m에서 temp 빼고 남은 결과도 마찬가지
		if (IsValid(firstWordMap, wordMap))
		{
			if (IsValid(wordMap, firstWordMap))
			{
				++answer;
			}
		}				
	}
	cout << answer;
	return 0;
}