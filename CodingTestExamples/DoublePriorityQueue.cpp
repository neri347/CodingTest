/// 이중 우선순위 큐
/// https://www.acmicpc.net/problem/7662
/// https://school.programmers.co.kr/learn/courses/30/lessons/42628
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		multiset<int> ms;
		for (int i = 0; i < N; i++)
		{
			char ch;
			cin >> ch;
			int num;
			cin >> num;

			if (ch == 'I')
			{
				ms.insert(num);
			}
			else
			{
				if (ms.empty())
				{
					continue;
				}

				if (num == 1) // 최대값 삭제
				{
					ms.erase(--ms.end());
				}
				else // 최소값 삭제
				{
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
		}
	}

	return 0;
}