/// 가르침
/// https://www.acmicpc.net/problem/1062
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int answer;
bool isVisited[26];
vector<string> voca;
string alphabets = "bdefghjklmopqrsuvwxyz";

int CountReadableVoca()
{
	int ret = 0;
	for (auto& str : voca)
	{
		bool flag = true; // 읽을 수 있는 단어인지 여부
		for (auto& ch : str)
		{
			if (!isVisited[ch - 'a'])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			++ret;
		}
	}
	return ret;
}

void Choose(int index, int count)
{
	if (count == K)
	{
		answer = max(answer, CountReadableVoca());
		return;
	}

	for (int i = index; i < alphabets.size(); i++)
	{
		isVisited[alphabets[i] - 'a'] = true;
		Choose(i + 1, count + 1);
		isVisited[alphabets[i] - 'a'] = false;
	}
}

int main()
{
	cin >> N >> K;	
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		string temp;
		for (int c = 4; c < str.size() - 4; c++)
		{
			temp += str[c];
		}
		voca.push_back(temp);
	}

	if (K < 5)
	{
		cout << answer;
		return 0;
	}

	string word = "actin";
	for (auto& ch : word)
	{
		isVisited[ch - 'a'] = true;
	}

	Choose(0, 5);
	cout << answer;
	return 0;
}