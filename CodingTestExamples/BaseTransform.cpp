/// 진법 변환2
/// https://www.acmicpc.net/problem/11005
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, b;
	cin >> n >> b;

	vector<int> ret;
	while (n >= b)
	{
		ret.push_back(n % b);
		n /= b;
	}
	ret.push_back(n);

	for (int i = ret.size() - 1; i >= 0; --i)
	{
		int num = ret[i];
		if (num >= 10)
		{
			char ch = 'A' - 10 + num;
			cout << ch;
		}
		else
		{
			char ch = num + '0';
			cout << ch;
		}
	}

	return 0;
}