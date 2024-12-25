/// N�� M
/// https://www.acmicpc.net/problem/15649
/// �ڿ��� N�� M�� �־����� ��, 
/// 1���� N���� �ڿ��� �߿��� �ߺ����� M���� �� ������ ���Ѵ�.
/// �ߺ��Ǵ� ������ ������ ������� �ʰ�, ���� ������ �����ϴ� ������ ����Ѵ�.
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