/// 3진법 뒤집기
/// https://school.programmers.co.kr/learn/courses/30/lessons/68935
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string ChangeToThreeBase(int val)
{
	string ret = "";
	while (val > 2)
	{
		ret += to_string(val % 3);
		val /= 3;
	}
	ret += to_string(val);
	reverse(ret.begin(), ret.end());
	return ret;
}

int solution(int n) {
	int answer = 0;
	string baseThree = ChangeToThreeBase(n);
	cout << baseThree;
	int m = 1; // 자릿수
	int index = 0;
	do
	{
		answer += (baseThree[index++] - '0') * m;
		m *= 3;
	} while (index < baseThree.size());
	return answer;
}

int main()
{

	return 0;
}