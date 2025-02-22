/// 표현 가능한 이진트리
/// https://school.programmers.co.kr/learn/courses/30/lessons/150367
/// 포화이진트리는 노드의 개수가 2^n - 1 개이다.
/// 주어진 수를 이진수로 변환했을 때 숫자의 개수가 2^n - 1개가 아니라면
/// 더미노드를 추가하여 2^n - 1개를 맞춰준다.
/// 그랬을 때 부모노드가 0일 때 자식노드가 1이라면 모순이므로
/// 주어진 수는 이진트리로 변환할 수 없는 수이다.
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
	return ret;
}

bool IsValid(const string& str)
{
	if (str.size() == 1)
	{
		return true;
	}

	int root = str.size() / 2;
	int left = root / 2;
	int right = (root + str.size()) / 2;
	if (str[root] == '0')
	{
		if (str[left] == '1' || str[right] == '1')
		{
			return false;
		}
	}
	string leftStr = str.substr(0, root);
	string rightStr = str.substr(root + 1, root);
	return IsValid(leftStr) && IsValid(rightStr);
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
		if (IsValid(str))
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
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}