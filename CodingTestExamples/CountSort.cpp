#include <iostream>
#include <vector>
#include <string>
using namespace std;

string CountSort(string str)
{
	string ret = "";
	vector<int> count(26, 0);
	for (const auto& c : str)
	{
		++count[c - 'a'];
	}

	for (int i = 0; i < count.size(); ++i)
	{
		ret += string(count[i], i + 'a');
	}

	return ret;
}

int main()
{
	string s = "algorithm";
	cout << CountSort(s);
	return 0;
}