/// 표현 가능한 이진트리
/// https://school.programmers.co.kr/learn/courses/30/lessons/150367
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string NumToStr(long long num)
{
	string ret = "";
	while (num >= 2)
	{
		ret += to_string(num % 2);
		num /= 2;
	}
	ret += to_string(num);
	//reverse(ret.begin(), ret.end());
	return ret;
}

bool IsValid(int index, const string& str)
{
	if (str.size() == 1)
	{
		return true;
	}

	int left = index / 2;
	int right = (index + str.size()) / 2;
	if (str[index] == '0')
	{
		if (str[left] == '1' || str[right] == '1')
		{
			return false;
		}
	}
	string leftStr = str.substr(0, index);
	string rightStr = str.substr(index + 1, index);
	return IsValid(left, leftStr) && IsValid(right, rightStr);
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;
	for (auto& number : numbers)
	{
		string str = NumToStr(number);
		// str에는 거꾸로 뒤집혀진 이진수가 있다.
		long long n = 2;
		while (true)
		{
			if (str.size() == n - 1)
			{
				break;
			}
			if (str.size() > n - 1 && str.size() < (n * 2 - 1))
			{
				// 뒤에 0 추가해서 size를 n*2-1로 만든다.
				long long count = (n * 2 - 1) - str.size();
				for (long long i = 0; i < count; i++)
				{
					str += "0";
				}
				break;
			}
			n *= 2;
		}
		reverse(str.begin(), str.end());
		// 부모가 0인데 자식이 1이라면 모순
		if (IsValid(str.size() / 2, str))
		{
			answer.push_back(1);
		}
		else
		{
			answer.push_back(0);
		}
	}
	return answer;
}

int main()
{
	vector<long long> numbers = { 63, 111, 95 };
	vector<int> answer = solution(numbers);
	return 0;
}