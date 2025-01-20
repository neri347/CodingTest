/// °íÃþ °Ç¹°
/// https://www.acmicpc.net/problem/1027
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int buildings[50];
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int height;
		cin >> height;
		buildings[i] = height;
	}

	vector<int> counts(N, 0);
	for (int i = 0; i < N; ++i)
	{
		double max_inclination = -9999999999;
		for (int j = i + 1; j < N; ++j)
		{
			double inclination = static_cast<double>(buildings[j] - buildings[i]) / (j - i);
			if (inclination > max_inclination)
			{
				max_inclination = inclination;
				counts[i]++;
				counts[j]++;
			}
		}
	}

	cout << *max_element(counts.begin(), counts.end());

	return 0;
}