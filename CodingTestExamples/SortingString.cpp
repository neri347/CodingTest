/// p.619 ����56_���ڿ� �� ������� �����ϱ�
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int idx;
bool Compare(const string& str1, const string& str2)
{
	// n��° ���ڿ� �������� ��������
	// n��° ���ڿ��� ������ ���������� ��������
	return str1[idx] == str2[idx] ? str1 < str2 : str1[idx] < str2[idx];
}

vector<string> solution(vector<string> strings, int n)
{
	idx = n;
	sort(strings.begin(), strings.end(), Compare);
	return strings;
}

int main()
{
	//vector<string> strings = { "sun","bed","car" };
	vector<string> strings = { "abce","abcd","cdx" };
	int n = 2;
	for (const auto& str : solution(strings, n))
	{
		cout << str << " ";
	}
	return 0;
}