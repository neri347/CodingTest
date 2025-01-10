/// ЦђБе
/// https://www.acmicpc.net/problem/1546
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> scores;
	for (int i = 0; i < n; ++i)
	{
		int score;
		cin >> score;
		scores.push_back(score);
	}

	int maxScore = *max_element(scores.begin(), scores.end());
	float sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += scores[i];
	}

	float total = sum / maxScore * 100;
	float avg = total / n;
	cout << avg;
	return 0;
}