/// ÀÇ»ó
/// https://school.programmers.co.kr/learn/courses/30/lessons/42578
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	unordered_map<string, vector<string>> m; // type, clothes name
	for (int i = 0; i < clothes.size(); i++)
	{
		string name = clothes[i][0];
		string type = clothes[i][1];
		m[type].push_back(name);
	}

	int combi = 1;
	for (auto& group : m)
	{
		combi *= (group.second.size() + 1);
	}

	return combi - 1;
}

int main()
{

	return 0;
}