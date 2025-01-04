/// 개인정보 수집 유효기간
/// https://school.programmers.co.kr/learn/courses/30/lessons/150370
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	unordered_map<string, int> termMap;
	vector<int> expirationDates;

	// 오늘 날짜 int로 변환
	stringstream todayss(today);
	vector<string> todayStrs;
	string buffer;
	while (getline(todayss, buffer, '.'))
	{
		todayStrs.push_back(buffer);
	}
	int year = stoi(todayStrs[0]) * 12 * 28;
	int month = stoi(todayStrs[1]) * 28;
	int day = stoi(todayStrs[2]);
	int todayTime = year + month + day;

	// 타입 별 기간 저장
	for (auto& str : terms)
	{
		stringstream ss(str);
		string type, term;
		ss >> type >> term;
		termMap[type] = stoi(term);
	}

	// privacies에 저장된 정보들을 토대로 파기날짜 저장
	for (const auto& str : privacies)
	{
		// 저장날짜 타입 저장
		stringstream ss1(str);
		string date, type;
		ss1 >> date >> type;

		// 저장날짜 + 저장기간
		stringstream ss2(date);
		string buffer;
		vector<string> ymd;
		while (getline(ss2, buffer, '.'))
		{
			ymd.push_back(buffer);
		}
		int year = stoi(ymd[0]) * 12 * 28;
		int month = stoi(ymd[1]) * 28;
		int day = stoi(ymd[2]);

		int expirationDate = year + month + day + termMap[type] * 28 - 1;
		expirationDates.push_back(expirationDate);
	}

	// 오늘 날짜와 파기날짜 비교해서 파기해야 하는 정보 인덱스+1 저장
	for (int i = 0; i < expirationDates.size(); ++i)
	{
		if (expirationDates[i] < todayTime)
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}

int main()
{
	string today = "2022.05.19";
	vector<string> terms = { "A 6", "B 12", "C 3" };
	vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };
	for (auto i : solution(today, terms, privacies))
	{
		cout << i << " ";
	}
	
	return 0;
}