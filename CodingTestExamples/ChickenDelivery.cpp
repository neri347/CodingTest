/// ġŲ ���
/// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickenJoints;
vector<int> selected;
int surviveCount;
int minDist = INT_MAX;

int CalcDistance()
{
	int ret = 0;
	// �� ������ ġŲ������ �Ÿ� ����
	for (int i = 0; i < houses.size(); ++i)
	{
		int hx = houses[i].first;
		int hy = houses[i].second;
		int d = INT_MAX; // ���������� ���� ����� ġŲ�������� �Ÿ�
		for (int j = 0; j < selected.size(); ++j)
		{
			if (selected[j] == 1)
			{
				int cx = chickenJoints[j].first;
				int cy = chickenJoints[j].second;
				int dist = abs(hx - cx) + abs(hy - cy);
				d = min(d, dist);
			}
		}
		ret += d;
	}

	return ret;
}

void SelectJoint()
{
	for (int i = 0; i < chickenJoints.size() - surviveCount; ++i)
	{
		selected.push_back(0);
	}
	for (int i = 0; i < surviveCount; ++i)
	{
		selected.push_back(1);
	}

	do
	{
		minDist = min(minDist, CalcDistance());
	} while (next_permutation(selected.begin(), selected.end()));
}

int main()
{
	// �Է�
	int n;
	cin >> n >> surviveCount;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;
			if (num == 1)
			{
				houses.push_back({ i, j });
			}
			else if (num == 2)
			{
				chickenJoints.push_back({ i,j });
			}
		}
	}

	// Ǯ��
	// ġŲ�� �� surviveCount���� ����, ġŲ�Ÿ� ��� �� ����
	SelectJoint();
	cout << minDist;

	return 0;
}