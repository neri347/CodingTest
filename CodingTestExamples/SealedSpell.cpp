/// 봉인된 주문
/// https://school.programmers.co.kr/learn/courses/30/lessons/389481
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(long long n, vector<string> bans) {
	string answer = "";
	vector<long long> nums;
	for (auto& str : bans)
	{
		long long value = 0;
		long long multi = 1;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			long long toNum = str[i] - 'a' + 1;
			value += toNum * multi;
			multi *= 26;
		}
		nums.push_back(value);
	}
	sort(nums.begin(), nums.end());

	for (auto& e : nums)
	{
		if (e <= n)
		{
			++n;
		}
		else
		{
			break;
		}
	}
	cout << n << endl;

	// n to str
	// v가 0인 경우 처리 필요하다.
	int carry = 0;
	while (n >= 26)
	{
		int v = n % 26;
		if (v == 0)
		{
			v = 26;
		}
		n /= 26;
		char ch = 'a' + v - carry - 1;
		answer += ch;

		if (v == 26)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
	}
	char ch = 'a' + n - carry - 1;
	answer += ch;
	reverse(answer.begin(), answer.end());

	return answer;
}

int main()
{

	return 0;
}