/// 컨베이어 벨트 위의 로봇
/// https://www.acmicpc.net/problem/20055
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// 로봇은 올리는 위치에만 올릴 수 있다. 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다. 
// 로봇을 올리는 위치에 올리거나 로봇이 어떤 칸으로 이동하면 그 칸의 내구도는 즉시 1만큼 감소한다.

int main()
{
	int N, K;
	cin >> N >> K;
	deque<pair<int, bool>> belt;
	for (int i = 0; i < 2 * N; i++)
	{
		int d;
		cin >> d;
		belt.push_back({ d, false });
	}

	int answer = 0;
	while (true)
	{
		++answer;
		// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
		auto back = belt.back();
		belt.pop_back();
		belt.push_front(back);
		// 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
		if (belt[N - 1].second)
		{
			belt[N - 1].second = false;
		}

		// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
		// 만약 이동할 수 없다면 가만히 있는다.
		//		1.로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
		for (int i = N - 2; i >= 0; i--)
		{
			if (belt[i].second && belt[i + 1].first >= 1 && belt[i + 1].second == false)
			{
				belt[i + 1].first--;
				belt[i + 1].second = true;
				belt[i].second = false;
			}
		}
		// 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
		if (belt[N - 1].second)
		{
			belt[N - 1].second = false;
		}

		// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		if (belt[0].first >= 1 && belt[0].second == false)
		{
			belt[0].first--;
			belt[0].second = true;
		}

		// 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.그렇지 않다면 1번으로 돌아간다.
		int count = 0;
		for (int i = 0; i < 2 * N; i++)
		{
			if (belt[i].first == 0)
			{
				++count;
			}
		}
		if (count >= K)
		{
			break;
		}
	}
	cout << answer;
	return 0;
}