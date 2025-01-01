/// 계단 오르기
/// https://www.acmicpc.net/problem/2579
/// 기초적인 DP 문제를 풀어보니,
/// DP 문제는 점화식 같은 형태로 이루어져 있는 경우가 많은 것 같다.
/// 문제가 잘 파악이 안 될 때는
/// 첫번째 케이스부터 몇 개의 케이스를 시뮬레이션 해서 
/// 결과를 도출해내면 규칙을 찾아낼 수가 있다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 입력
	int size;
	cin >> size;
	vector<int> stairScores;
	for (int i = 0; i < size; ++i)
	{
		int score;
		cin >> score;
		stairScores.push_back(score);
	}

	// 풀이
	vector<int> dp(size);
	dp[0] = stairScores[0];
	dp[1] = stairScores[0] + stairScores[1];
	dp[2] = max(stairScores[0] + stairScores[2], stairScores[1] + stairScores[2]);

	for (int i = 3; i < size; ++i)
	{
		dp[i] = max(stairScores[i] + stairScores[i - 1] + dp[i - 3], stairScores[i] + dp[i - 2]);
	}

	cout << dp[size - 1];

	return 0;
}