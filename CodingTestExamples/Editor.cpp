/// ¿¡µğÅÍ
/// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	list<char> charList;
	string input;
	cin >> input;
	for (auto& ch : input)
	{
		charList.push_back(ch);
	}
	int pos = charList.size();
	auto iter = charList.end();

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		char command;
		cin >> command;
		if (command == 'L')
		{
			if (iter != charList.begin())
			{
				--iter;
			}
		}
		else if (command == 'D')
		{

			if (iter != charList.end())
			{
				++iter;
			}
		}
		else if (command == 'B')
		{
			if (iter != charList.begin())
			{
				--iter;
				iter = charList.erase(iter);
			}
		}
		else
		{
			char ch;
			cin >> ch;
			iter = charList.insert(iter, ch);
			++iter;
		}
	}
	
	for (auto& ch : charList)
	{
		cout << ch;
	}

	return 0;
}