/// ¹°º´
/// https://www.acmicpc.net/problem/1052
#include <iostream>
#include <vector>
using namespace std;

int Calculate(int n)
{
	int ret = 0;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			ret++;
		}
		n /= 2;
	}
	return ret;
}

int main()
{
	int N, K;
	cin >> N >> K;
	int answer = 0;
	if (N > K)
	{
		while (true)
		{
			int count = Calculate(N);
			if (count <= K)
			{
				break;
			}
			++answer;
			++N;
		}
	}
	cout << answer;
	return 0;
}