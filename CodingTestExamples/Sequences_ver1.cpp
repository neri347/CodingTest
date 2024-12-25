/// N과 M
/// https://www.acmicpc.net/problem/15649
/// 자연수 N과 M이 주어졌을 때, 
/// 1부터 N까지 자연수 중에서 중복없이 M개를 고른 수열을 구한다.
/// 중복되는 수열을 여러번 출력하지 않고, 사전 순으로 증가하는 순서로 출력한다.
#include <iostream>
#include <vector>
using namespace std;

vector<bool> isVisited(9, false);
vector<int> temp;

void BackTrack(int cur, int max, int count)
{
	if (temp.size() >= count)
	{
		for (int n : temp)
		{
			cout << n << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= max; ++i)
	{
		if (!isVisited[i])
		{
			temp.push_back(i);
			isVisited[i] = true;
			BackTrack(i, max, count);
			temp.pop_back();
			isVisited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	BackTrack(0, N, M);
	return 0;
}