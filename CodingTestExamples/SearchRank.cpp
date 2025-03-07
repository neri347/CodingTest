/// 순위 검색
/// https://school.programmers.co.kr/learn/courses/30/lessons/72412
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<int>> m;

void DFS(int index, int count, int maxCount, int score, vector<string>& keywords, vector<int>& chooseIdx)
{
	if (count == maxCount)
	{
		vector<string> temp = keywords;
		for (auto& idx : chooseIdx)
		{
			temp[idx] = "-";
		}

		string result = "";
		for (auto& str : temp)
		{
			result += str;
		}
		m[result].push_back(score);
		return;
	}

	for (int i = index; i < 4; i++)
	{
		chooseIdx.push_back(i);
		DFS(i + 1, count + 1, maxCount, score, keywords, chooseIdx);
		chooseIdx.pop_back();
	}
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	for (int i = 0; i < info.size(); i++)
	{
		string str = info[i];
		stringstream ss(str);
		string l, w, c, sf, sc;
		ss >> l >> w >> c >> sf >> sc;
		int score = stoi(sc);
		vector<string> keywords;
		keywords.push_back(l);
		keywords.push_back(w);
		keywords.push_back(c);
		keywords.push_back(sf);
		vector<int> chooseIdx;
		for (int i = 0; i < 5; i++)
		{
			DFS(0, 0, i, score, keywords, chooseIdx);
		}
	}

	// 각 점수 데이터 정렬
	for (auto& p : m)
	{
		sort(p.second.begin(), p.second.end());
	}

	for (auto& str : query)
	{
		stringstream ss(str);
		vector<string> strVec;
		string temp;
		while (getline(ss, temp, ' '))
		{
			strVec.push_back(temp);
		}

		// strVec[0], strVec[2], strVec[4], strVec[6], strVec[7]
		string keyword = "";
		keyword += strVec[0];
		keyword += strVec[2];
		keyword += strVec[4];
		keyword += strVec[6];
		int score = stoi(strVec[7]);

		vector<int>& value = m[keyword];
		int count = value.end() - lower_bound(value.begin(), value.end(), score);
		answer.push_back(count);
	}

	return answer;
}

int main()
{

	return 0;
}