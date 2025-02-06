/// 이진 변환 반복하기
/// https://school.programmers.co.kr/learn/courses/30/lessons/70129
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string ChangeToBinary(int val)
{
	string ret = "";
	while (val > 1)
	{
		ret += to_string(val % 2);
		val /= 2;
	}
	ret += to_string(val);
	reverse(ret.begin(), ret.end());
	return ret;
}

vector<int> solution(string s) {
	int changeCount = 0;
	int deleteCount = 0;
	while (s != "1")
	{
		int beforeLen = s.size();
		s.erase(remove(s.begin(), s.end(), '0'), s.end());
		int afterLen = s.size();
		deleteCount += (beforeLen - afterLen);

		s = ChangeToBinary(afterLen);
		++changeCount;
	}
	return { changeCount, deleteCount };
}

int main()
{
	string s = "110010101001";
	solution(s);
	return 0;
}