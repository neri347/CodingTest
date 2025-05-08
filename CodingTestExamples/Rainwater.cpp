/// ºø¹°
/// https://www.acmicpc.net/problem/14719
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<int> heights(W);
	for (int i = 0; i < W; i++)
	{
		cin >> heights[i];
	}

	int answer = 0;
	for (int i = 1; i < W - 1; i++)
	{
		int left = 0;
		int right = 0;
		for (int j = 0; j < i; j++)
		{
			left = max(left, heights[j]);
		}
		for (int j = i + 1; j < W; j++)
		{
			right = max(right, heights[j]);
		}

		answer += max(0, min(left, right) - heights[i]);
	}
	cout << answer;
	return 0;
}