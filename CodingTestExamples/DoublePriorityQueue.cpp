/// 이중우선순위큐
/// https://school.programmers.co.kr/learn/courses/30/lessons/42628
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
	multiset<int> ms;

	for (auto& str : operations)
	{
		stringstream ss(str);
		string command, num;
		ss >> command >> num;

		if (command == "I")
		{
			int n = stoi(num);
			ms.insert(n);
		}
		else
		{
			if (num == "1")
			{
				if (!ms.empty())
				{
					// 최대값 삭제
					ms.erase(--ms.end());
				}
			}
			else
			{
				if (!ms.empty())
				{
					// 최소값 삭제
					ms.erase(ms.begin());
				}
			}
		}
	}

	if (ms.empty())
	{
		return { 0, 0 };
	}

	return { *(--ms.end()), *ms.begin() };
}

int main()
{

	return 0;
}