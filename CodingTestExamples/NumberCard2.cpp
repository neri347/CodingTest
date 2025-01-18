/// 숫자 카드 2
/// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	vector<int> answer;
	int N;
	cin >> N;
	unordered_map<int, int> cards;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		cards[num]++;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int num;
		cin >> num;
		if (cards.count(num))
		{
			answer.push_back(cards[num]);
		}
		else
		{
			answer.push_back(0);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}

	return 0;
}