/// 알람시계
/// https://www.acmicpc.net/problem/2884
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;

	int time = 60 * h + m;
	time -= 45;
	if (time < 0)
	{
		time += 24 * 60;
	}
	int hour = time / 60;
	int minute = time - hour * 60;
	cout << hour << " " << minute;
	return 0;
}