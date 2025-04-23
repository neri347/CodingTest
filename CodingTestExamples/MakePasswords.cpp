/// 암호 만들기
/// https://www.acmicpc.net/problem/1759
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int L, C;
vector<char> chars;

void DFS(int index, int vowelCount, int consonantCount, vector<char>& vec)
{
	if (vec.size() == L)
	{
		if (vowelCount >= 1 && consonantCount >= 2)
		{
			string str;
			for (auto& ch : vec)
			{
				str += ch;
			}
			cout << str << '\n';
		}
		return;
	}

	for (int i = index; i < chars.size(); i++)
	{
		char ch = chars[i];
		vec.push_back(ch);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			DFS(i + 1, vowelCount + 1, consonantCount, vec);
		}
		else
		{
			DFS(i + 1, vowelCount, consonantCount + 1, vec);
		}
		vec.pop_back();
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char ch;
		cin >> ch;
		chars.push_back(ch);
	}
	sort(chars.begin(), chars.end());

	vector<char> vec;
	DFS(0, 0, 0, vec);

	return 0;
}