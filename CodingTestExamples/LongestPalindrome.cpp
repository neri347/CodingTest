/// 가장 긴 팰린드롬
/// https://school.programmers.co.kr/learn/courses/30/lessons/12904
#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

bool Search(int start, int length, const string& str)
{
	int left = start;
	int right = start + length - 1;
	while (left < right)
	{
		if (str[left] != str[right])
		{
			return false;
		}
		++left;
		--right;
	}
	return true;
}

int solution(string s)
{
	int answer = 1;
	int sz = s.size();
	while (true)
	{
		for (int len = sz; len >= 2; len--)
		{
			for (int start = 0; start <= sz - len; start++)
			{
				if (Search(start, len, s))
				{
					answer = len;
					return answer;
				}
			}
		}
		return answer;
	}
}

int main()
{
	
	return 0;
}