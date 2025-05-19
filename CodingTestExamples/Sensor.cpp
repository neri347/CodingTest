/// ¼¾¼­
/// https://www.acmicpc.net/problem/2212
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> sensors;
	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;
		sensors.push_back(p);
	}
	sort(sensors.begin(), sensors.end());

	vector<int> dist;
	for (int i = 0; i < N - 1; i++)
	{
		dist.push_back(sensors[i + 1] - sensors[i]);
	}
	sort(dist.rbegin(), dist.rend());

	int answer = 0;
	for (int i = K - 1; i < dist.size(); i++)
	{
		answer += dist[i];
	}

	cout << answer;
	return 0;
}