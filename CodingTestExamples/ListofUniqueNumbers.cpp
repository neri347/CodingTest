/// List of Unique Numbers
/// https://www.acmicpc.net/problem/13144
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long answer = 0;
	vector<int> vec(N);
	vector<bool> isVisited(N + 1, false);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	int end = 0;
	for (int start = 0; start < N; start++)
	{
		while (end < N)
		{
			if (isVisited[vec[end]])
				break;
			isVisited[vec[end]] = true;
			++end;
		}
		answer += end - start;
		isVisited[vec[start]] = false;
	}
	cout << answer;
	return 0;
}