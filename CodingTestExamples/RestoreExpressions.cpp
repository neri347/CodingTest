/// ���� �����ϱ�
/// https://school.programmers.co.kr/learn/courses/30/lessons/340210
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

string ChangeBase(int base, int value)
{
	string str = "";
	while (value >= base)
	{
		str += to_string(value % base);
		value /= base;
	}
	str += to_string(value);
	reverse(str.begin(), str.end());
	return str;
}

string Calc(int base, string n1, string n2, string command)
{
	// n1, n2 -> 10����
	int num1 = 0;
	int t = 1;
	for (int i = n1.size() - 1; i >= 0; i--)
	{
		int n = (n1[i] - '0') * t;
		num1 += n;
		t *= base;
	}

	int num2 = 0;
	t = 1;
	for (int i = n2.size() - 1; i >= 0; i--)
	{
		int n = (n2[i] - '0') * t;
		num2 += n;
		t *= base;
	}

	int value = 0;
	if (command == "+")
	{
		value = num1 + num2;
	}
	else
	{
		value = num1 - num2;
	}

	string ret = ChangeBase(base, value);
	//cout << "Changed : " << ret;
	return ret;
}

vector<string> solution(vector<string> expressions) {
	vector<string> answer;
	unordered_map<int, set<string>> um;

	int maxValue = 0;
	for (auto& str : expressions)
	{
		stringstream ss(str);
		string n1, command, n2, equal, result;
		ss >> n1 >> command >> n2 >> equal >> result;
		// ���ĵ��� ���ڵ��� �� �ڸ��� ���� �� ���� ū �� �˻�
		for (int i = 0; i < n1.size(); i++)
		{
			int toInt = n1[i] - '0';
			maxValue = max(maxValue, toInt);
		}

		for (int i = 0; i < n2.size(); i++)
		{
			int toInt = n2[i] - '0';
			maxValue = max(maxValue, toInt);
		}

		if (result != "X")
		{
			for (int i = 0; i < result.size(); i++)
			{
				int toInt = result[i] - '0';
				maxValue = max(maxValue, toInt);
			}
		}
		else
		{
			string expStr = n1 + " " + command + " " + n2 + " " + equal + " ";
			answer.push_back(expStr);
		}
	}
	++maxValue;

	for (int i = maxValue; i <= 9; i++) // i = ����
	{
		vector<string> temp;
		for (int j = 0; j < expressions.size(); j++)
		{
			string str = expressions[j];
			stringstream ss(str);
			string n1, command, n2, equal, result;
			ss >> n1 >> command >> n2 >> equal >> result;

			if (result == "X")
			{
				temp.push_back(Calc(i, n1, n2, command));
			}
			else
			{
				if (Calc(i, n1, n2, command) != result)
				{
					temp.clear();
					break;
				}
			}
		}

		for (int i = 0; i < temp.size(); i++)
		{
			um[i].insert(temp[i]);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (um[i].size() > 1)
		{
			answer[i] += "?";
		}
		else
		{
			answer[i] += *(um[i].begin());
		}
	}

	return answer;
}

int main()
{

	return 0;
}