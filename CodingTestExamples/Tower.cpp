/// 탑
/// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <vector>
using namespace std;

int tower[500001];
int receiver[500001];

int Find(int cur, int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (tower[cur] <= tower[n])
	{
		return n;
	}
	return Find(cur, receiver[n]);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> tower[i];
	}

	receiver[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		receiver[i] = Find(i, i - 1);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << receiver[i] << " ";
	}

	return 0;
}