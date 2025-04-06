/// �ù�
/// https://www.acmicpc.net/problem/8980
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Parcel
{
	int from, to, count;
};

bool Cmp(const Parcel& a, const Parcel& b)
{
	// �޴� ���� ��ȣ ���� ��, ������ ���� ��ȣ ���� ������ ����
	if (a.to == b.to)
	{
		return a.from < b.from;
	}
	return a.to < b.to;
}

int main()
{
	int N, C;
	cin >> N >> C;
	int M;
	cin >> M;
	vector<Parcel> parcels;
	for (int i = 0; i < M; i++)
	{
		int from, to, count;
		cin >> from >> to >> count;
		parcels.push_back({from, to, count});
	}

	sort(parcels.begin(), parcels.end(), Cmp);

	int answer = 0;
	vector<int> weights(N, 0);
	for (int i = 0; i < M; i++)
	{
		int from = parcels[i].from;
		int to = parcels[i].to;
		int count = parcels[i].count;

		int maxWeight = 0;
		// Ʈ���� from ~ to - 1 ���� ���µ� ����� ������ �ִ밪. Ʈ���뷮���� �� �ִ밪�� �� ��ŭ Ʈ���� �� ���� �� �ִ�.
		for (int j = from; j < to; j++)
		{
			maxWeight = max(maxWeight, weights[j]);
		}
		
		int deliveryCount = min(count, C - maxWeight);
		// Ʈ���� from ~ to - 1���� ���µ� deliveryCount ��ŭ ���Ը� ����� ���̹Ƿ� �迭�� �����ش�.
		for (int j = from; j < to; j++)
		{
			weights[j] += deliveryCount;
		}
		answer += deliveryCount;
	}
	
	cout << answer;
	return 0;
}