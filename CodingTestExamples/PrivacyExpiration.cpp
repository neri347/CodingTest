/// �������� ���� ��ȿ�Ⱓ
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

	// ���� ��¥ int�� ��ȯ
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

	// Ÿ�� �� �Ⱓ ����
	for (auto& str : terms)
	{
		stringstream ss(str);
		string type, term;
		ss >> type >> term;
		termMap[type] = stoi(term);
	}

	// privacies�� ����� �������� ���� �ı⳯¥ ����
	for (const auto& str : privacies)
	{
		// ���峯¥ Ÿ�� ����
		stringstream ss1(str);
		string date, type;
		ss1 >> date >> type;

		// ���峯¥ + ����Ⱓ
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

	// ���� ��¥�� �ı⳯¥ ���ؼ� �ı��ؾ� �ϴ� ���� �ε���+1 ����
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