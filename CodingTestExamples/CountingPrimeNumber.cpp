/// k진수에서 소수 개수 구하기
/// https://school.programmers.co.kr/learn/courses/30/lessons/92335
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string ChangeBase(int n, int k)
{
	string str = "";
	vector<int> vec;
	while (n >= k)
	{
		int r = n % k;
		vec.push_back(r);
		n /= k;
	}
	vec.push_back(n);

	for (int i = vec.size() - 1; i >= 0; --i)
	{
		str += to_string(vec[i]);
	}
	return str;
}

bool IsPrime(string str)
{
	long long num = stoll(str);
	if (num < 2)
	{
		return false;
	}

	for (long long i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
	int answer = 0;
	string str = ChangeBase(n, k);
	string temp = "";
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '0')
		{
			if (temp.size() > 0)
			{
				// 소수인지 확인
				if (IsPrime(temp))
				{
					++answer;
				}
				temp = "";
			}
			else
			{
				temp = "";
			}
		}
		else
		{
			temp += str[i];
		}
	}

	if (temp.size() > 0)
	{
		if (IsPrime(temp))
		{
			++answer;
		}
	}

	return answer;
}

int main()
{

	return 0;
}